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
    int X, Y, E;
    cin >> X >> Y >> E;

    // 0~X-1..コンピュータ
    // X~X+Y-1..仕事

    int s = X + Y; // 始点
    int t = s + 1; // 終点
    // sとコンピュータを接続
    rep(i, X) {
        add_edge(s, i, 1);
    }
    // 仕事とtを接続
    rep(i, Y) {
        add_edge(X + i, t, 1);
    }
    // コンピュータと仕事を接続
    rep(i, E) {
        int x, y;
        cin >> x >> y;
        add_edge(x, X + y, 1);
    }

    int ans = max_flow(s, t);

    cout << ans << endl;
    return 0;
}

/*
in:
3 3 5
0 0
0 1
1 0
1 2
2 1

out:
3
*/