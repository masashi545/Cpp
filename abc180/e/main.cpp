#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    vector<vector<int>> d(n, vector<int>(n, INF));
    rep(i, n) {
        int a = x[i], b = y[i], c = z[i];
        rep(j, n) {
            int p = x[j], q = y[j], r = z[j];
            d[i][j] = abs(p - a) + abs(q - b) + max(0, r - c);
        }
    }

    // dp[S][v]..S:すでに訪れた頂点集合, v:現在いる頂点
    // この状態から、残りの全ての頂点をめぐって頂点0に戻る経路の最小値
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    dp[(1 << n) - 1][0] = 0; // 1111..11 つまり全ての頂点を訪れた場合

    for (int S = (1 << n) - 2; S >= 0; --S) {
        rep(v, n) {
            rep(u, n) {
                if (!(S >> u & 1)) { // uにまだ訪れていなかったら更新
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
                }
            }
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}