#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct edge {
    int to;
    int cost;
};

int n;
vector<vector<edge>> G(100000);

vector<int> dijkstra(int s, int t) {
    vector<int> d(n, INF);                        // 各頂点の始点からの最短距離
    vector<int> prev(n, -1);                      // 最短路を辿るときの直前の頂点
    priority_queue<P, vector<P>, greater<P>> que; // 最短距離が確定した頂点に隣接している頂点（first:暫定の最短距離、 second:頂点）
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        // まだ使われていない頂点のうち、距離が最小のものを探す
        P p = que.top();
        que.pop();
        int v = p.second; // vについては最短距離確定

        if (d[v] < p.first)
            continue;

        // vと隣接している頂点について、最短距離を更新
        rep(i, int(G[v].size())) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                prev[e.to] = v;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    // 始点sから各頂点への最短経路長を返す
    return d;
    // 始点sから終点tへの最短経路を返す
    /*
    vector<int> path;
    for (; t != -1; t = prev[t]) {
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    return path;
    */
}

int main() {
    int m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x - 1].push_back(edge{y - 1, w});
        G[y - 1].push_back(edge{x - 1, w});
    }

    vector<int> dist = dijkstra(s - 1, t - 1);

    rep(i, dist.size()) cout << dist[i] << " ";
    cout << endl;
    return 0;
}