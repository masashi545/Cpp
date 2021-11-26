#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

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
    int n, k;
    cin >> n >> k;
    vector<P> ast;

    // 0~n-1..横方向ビーム
    // n~2n-1..縦方向ビーム

    int s = 2 * n; // 始点
    int t = s + 1; // 終点
    // sと横方向を接続
    rep(i, n) {
        Dinic::add_edge(s, i, 1);
    }
    // 縦方向とtを接続
    rep(i, n) {
        Dinic::add_edge(n + i, t, 1);
    }
    // 横方向と縦方向を接続
    rep(i, k) {
        int r, c;
        cin >> r >> c;
        Dinic::add_edge(--r, n + c - 1, 1);
    }

    int ans = Dinic::max_flow(s, t);

    cout << ans << endl;
}

/*
in:
3
4
1 1
1 3
2 2
3 2

out:
2
*/
