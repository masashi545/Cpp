#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e12 + 7;

int N;
const int MAX_N = 310;
vector<vector<ll>> d(MAX_N, vector<ll>(MAX_N, INF)); // 各頂点間の最短距離

void warshall_floyd() {
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

namespace MaxFlow {

struct edge {
    int to;  // 行き先
    int cap; // 容量
    int rev; // 逆辺
};

const int INF = 1e9 + 7;

int MAX_V = 1000;
vector<vector<edge>> G(MAX_V); // グラフの隣接行列
vector<bool> used(MAX_V);      // DFSで既に調べたかのフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back(edge{to, cap, (int)G[to].size()});
    G[to].push_back(edge{from, 0, (int)G[from].size() - 1});
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v == t)
        return f;
    used[v] = true;
    rep(i, G[v].size()) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        used.assign(MAX_V, false);
        int f = dfs(s, t, INF);
        if (f == 0)
            return flow;
        flow += f;
    }
}

} // namespace MaxFlow

int main() {
    int M;
    cin >> N >> M;
    rep(i, M) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
        d[v - 1][u - 1] = w;
    }
    rep(i, N) d[i][i] = 0;

    warshall_floyd();

    int K;
    cin >> K;
    vector<int> a(K);
    rep(i, K) {
        cin >> a[i];
        a[i]--;
    }
    int Q;
    cin >> Q;
    vector<int> b(Q);
    rep(i, Q) {
        cin >> b[i];
        b[i]--;
    }

    // 二分探索
    ll l = -1, r = INF;
    while (r - l > 1) {
        // cout << "l : " << l << endl;
        // cout << "r : " << r << endl;
        ll md = (l + r) / 2;
        // すべてのスタンプ間をmd以内で移動できるか？
        vector<int> over; // 通路での最短距離がmdを超える区間の行き先
        rep(i, K - 1) {
            if (d[a[i]][a[i + 1]] > md) {
                over.push_back(a[i + 1]);
            }
        }
        int X = over.size();

        // 0~X-1..行き先
        // X~X+Q-1..魔法の石(出発点)

        int s = X + Q;
        int t = s + 1;

        // sと行き先を接続
        rep(i, X) {
            MaxFlow::add_edge(s, i, 1);
        }
        // 魔法の石とtを接続
        rep(i, Q) {
            MaxFlow::add_edge(X + i, t, 1);
        }
        // 行き先と魔法の石(出発点)を接続
        rep(i, X) {
            rep(j, Q) {
                if (d[b[j]][over[i]] <= md) { // 魔法の石を使った上での最短距離がmd以下であれば、OK
                    MaxFlow::add_edge(i, X + j, 1);
                }
            }
        }

        int ans = MaxFlow::max_flow(s, t);
        // cout << "ans : " << ans << endl;
        // 隣接グラフを初期化
        MaxFlow::G.assign(MaxFlow::MAX_V, vector<MaxFlow::edge>(0));

        if (ans >= X) {
            r = md;
        } else {
            l = md;
        }
    }

    cout << r << endl;
    return 0;
}