#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e13 + 7;

struct edge {
    int from;
    int to;
    ll cost;
};

int n, m;
vector<edge> es(2100); // 枝集合 10000 <- M_MAX
vector<ll> d(1100);    // 各頂点への最短距離 10000 <- N_MAX

bool update;

void bellman_ford(int s) {
    d[s] = 0;
    rep(k, n) {
        update = false;
        rep(i, m) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        es[i] = edge{u - 1, v - 1, -w};
    }

    d.assign(n, INF);
    bellman_ford(0);

    // 負の閉路がないかチェック
    if (update) { // n回目も更新があったら負の閉路がある
        cout << "inf" << endl;
        return 0;
    }

    cout << -d[n - 1] << endl;
    return 0;
}
