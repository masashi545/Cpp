#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct edge {
    int to;  // 行き先
    int cap; // 容量
    int rev; // 逆辺
};

int MAX_V = 210;
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

int main() {
    int N, G, E;
    cin >> N >> G >> E;
    // 頂点数は、SNSの登録者数N(高橋くん含む)と、マークした女の子の数G
    int V = N + G;
    rep(i, G) {
        int p;
        cin >> p;
        add_edge(p, N + i, 1);
    }
    rep(i, E) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }

    int ans = 0;
    rep(i, G) {
        int cut = max_flow(0, N + i);
        ans += cut;
        // cout << cut << endl;
    }

    cout << ans << endl;
    return 0;
}