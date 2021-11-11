#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

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
    int N;
    cin >> N;

    // 0~N-1..赤い点
    // N~2N-1..青い点

    int s = 2 * N; // 始点
    int t = s + 1; // 終点
    // sと赤い点を接続
    rep(i, N) {
        add_edge(s, i, 1);
    }
    // 青い点とtを接続
    rep(i, N) {
        add_edge(N + i, t, 1);
    }
    // 赤い点と青い点を接続
    vector<int> a(N), b(N), c(N), d(N);
    rep(i, N) cin >> a[i] >> b[i];
    rep(i, N) cin >> c[i] >> d[i];
    rep(i, N) {
        rep(j, N) {
            if (a[i] < c[j] && b[i] < d[j]) {
                add_edge(i, N + j, 1);
            }
        }
    }

    int ans = max_flow(s, t);

    cout << ans << endl;
    return 0;
}