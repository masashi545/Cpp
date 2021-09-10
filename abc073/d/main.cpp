#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int n;
vector<vector<int>> d(210, vector<int>(210, INF));

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
    int m, r;
    cin >> n >> m >> r;
    vector<int> town(r);
    rep(i, r) {
        cin >> town[i];
        town[i]--;
    }
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
        d[v - 1][u - 1] = w;
    }
    rep(i, n) d[i][i] = 0;

    warshall_floyd();

    int ans = INF;
    sort(town.begin(), town.end());
    do {
        int sum = 0;
        rep(i, r - 1) {
            sum += d[town[i]][town[i + 1]]; // i->i+1の距離を足していく
        }
        ans = min(ans, sum);
    } while (next_permutation(town.begin(), town.end()));

    cout << ans << endl;
    return 0;
}