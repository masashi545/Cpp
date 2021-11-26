#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

namespace Dinic {

struct edge {
    int to;  // 行き先
    int cap; // 容量
    int rev; // 逆辺
};

int MAX_V = 1010;
vector<vector<edge>> G(MAX_V); // グラフの隣接リスト
vector<int> level(MAX_V);      // sからの距離
vector<int> iter(MAX_V);       // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back(edge{to, cap, (int)G[to].size()});
    G[to].push_back(edge{from, 0, (int)G[from].size() - 1});
}

// sからの最短距離をBFSで計算する
void bfs(int s) {
    level.assign(MAX_V, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        rep(i, G[v].size()) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v == t)
        return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
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
        bfs(s);
        if (level[t] < 0)
            return flow;
        iter.assign(MAX_V, 0);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

} // namespace Dinic

int main() {
    vector<int> ans;
    while (true) {
        int M, N;
        cin >> M >> N;

        if (M == 0 && N == 0) {
            break;
        }

        Dinic::G.assign(Dinic::MAX_V, vector<Dinic::edge>(0)); // 隣接リストの初期化

        // 0~M-1..青いカード
        // M~M+N-1..赤いカード

        int s = M + N; // 始点
        int t = s + 1; // 終点
        // sと青いカードを接続
        rep(i, M) {
            Dinic::add_edge(s, i, 1);
        }
        // 赤いカードとtを接続
        rep(i, N) {
            Dinic::add_edge(M + i, t, 1);
        }
        // 青いカードと赤いカードを接続
        vector<int> b(M), r(N);
        rep(i, M) cin >> b[i];
        rep(i, N) cin >> r[i];
        rep(i, M) {
            rep(j, N) {
                if (gcd(b[i], r[j]) > 1) {
                    Dinic::add_edge(i, M + j, 1);
                }
            }
        }

        int flow = Dinic::max_flow(s, t);
        ans.push_back(flow);
        // cout << flow << endl;
    }

    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}