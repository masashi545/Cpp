#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

struct edge {
    int from;
    int to;
    int cost;
};

int n, m;
vector<edge> es(2100); // 枝集合 10000 <- M_MAX
vector<int> d(1100);   // 各頂点への最短距離 10000 <- N_MAX

bool update;

void bellman_ford(int s) {
    d[s] = 0;
    rep(k, n + 1) {
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
    int s;
    cin >> s;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = edge{u, v, w};
    }

    // 負の閉路がないかチェック
    d.assign(n, INF);
    bellman_ford(s);
    if (update) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i, n) {
        if (d[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << d[i] << endl;
        }
    }
    return 0;
}