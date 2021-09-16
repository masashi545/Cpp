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

int main() {
    cin >> n >> m;
    rep(i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        es[i] = edge{u - 1, v - 1, -w};
    }

    d.assign(n, INF);
    // まず、n-1回の更新
    d[0] = 0;
    rep(k, n - 1) {
        rep(i, m) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }

    ll ans = -d[n - 1];

    // nへの経路に影響を及ぼす負閉路があったらinf
    // つまり、もう一度n回の更新を行い、nに関わる更新があったらinf
    bool update = false;
    rep(k, n) {
        rep(i, m) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (e.to == n - 1) {
                    update = true;
                }
            }
        }
    }

    if (update) {
        cout << "inf" << endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}
