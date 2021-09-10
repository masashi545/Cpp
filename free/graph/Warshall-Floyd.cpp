#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int n;
vector<vector<int>> d(100, vector<int>(100, INF));

void warshall_floyd() {
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
        d[v - 1][u - 1] = w;
    }
    rep(i, n) d[i][i] = 0;

    warshall_floyd();

    return 0;
}