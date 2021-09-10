#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int n;
vector<vector<int>> d(310, vector<int>(310, INF)); // d[i][j]...iからjへの最短距離

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
        int a, b, t;
        cin >> a >> b >> t;
        d[a - 1][b - 1] = t;
        d[b - 1][a - 1] = t;
    }
    rep(i, n) d[i][i] = 0;

    warshall_floyd();

    int ans = INF;
    rep(i, n) {
        int maxl = 0; // iから最短で各頂点へ行くときの最大のコスト
        rep(j, n) {
            maxl = max(maxl, d[i][j]);
        }
        ans = min(ans, maxl); // 最大のコストが最も小さいものを求める
    }

    cout << ans << endl;
    return 0;
}