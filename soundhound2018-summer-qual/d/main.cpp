#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;
int const INF = 1e9 + 7;

struct edge {
    int to;
    ll yen, snuuk;
};

int n;
vector<vector<edge>> G(100010);

vector<ll> dijkstra(int s, bool b) {
    vector<ll> d(n, INF);                         // 各頂点の始点からの最短距離
    priority_queue<P, vector<P>, greater<P>> que; // 最短距離が確定した頂点に隣接している頂点（first:暫定の最短距離、 second:頂点）
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        // まだ使われていない頂点のうち、距離が最小のものを探す
        P p = que.top();
        que.pop();
        ll v = p.second; // vについては最短距離確定

        if (d[v] < p.first)
            continue;

        // vと隣接している頂点について、最短距離を更新
        rep(i, int(G[v].size())) {
            edge e = G[v][i];
            ll cost = b ? e.yen : e.snuuk;
            if (d[e.to] > d[v] + cost) {
                d[e.to] = d[v] + cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    // 始点sから各頂点への最短経路長を返す
    return d;
}

int main() {
    int m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    rep(i, m) {
        int x, y;
        ll a, b;
        cin >> x >> y >> a >> b;
        G[x - 1].push_back(edge{y - 1, a, b});
        G[y - 1].push_back(edge{x - 1, a, b});
    }

    vector<ll> dyen = dijkstra(s - 1, true);    // 始点からのyenを使った最短距離
    vector<ll> dsnuuk = dijkstra(t - 1, false); // 終点からのsnukeを使った最短距離

    priority_queue<P, vector<P>, greater<P>> que;
    rep(i, n) {
        que.push(P(dyen[i] + dsnuuk[i], i));
    }

    P p = que.top();
    que.pop();
    rep(i, n) {
        while (p.second < i) {
            p = que.top();
            que.pop();
        }
        ll ans = 1e15;
        ans -= p.first;
        cout << ans << endl;
    }
    return 0;
}