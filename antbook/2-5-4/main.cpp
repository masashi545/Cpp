#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct edge {
    int from;
    int to;
    int cost;
};

int n, ml, md;
vector<edge> es(21100); // 10000 <- M_MAX
vector<int> d(1100);    // 10000 <- N_MAX

bool updated;

void bellman_ford() {
    rep(k, n + 1) {
        updated = false;
        rep(i, n + ml + md - 1) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                updated = true;
            }
        }
    }
}

int main() {
    cin >> n >> ml >> md;
    rep(i, ml) {
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = edge{u - 1, v - 1, w};
    }
    rep(i, md) {
        int u, v, w;
        cin >> u >> v >> w;
        es[i + ml] = edge{v - 1, u - 1, -w};
    }
    rep(i, n - 1) {
        es[i + ml + md] = edge{i + 1, i, 0};
    }

    // 負の閉路があったら、不可能
    d.assign(n, 0);
    bellman_ford();
    if (updated) { // n+1回目も更新があったら、負の閉路がある
        cout << -1 << endl;
        return 0;
    }

    d.assign(n, INF);
    d[0] = 0;
    bellman_ford();
    int ans = d[n - 1];
    if (ans == INF) // nに到達できない場合は、最短距離が無限大。つまりいくらでも大きくできる
        ans = -2;

    cout << ans << endl;
    return 0;
}

/*
in:
4 2 1
1 3 10
2 4 20
2 3 3 

out:
27
*/