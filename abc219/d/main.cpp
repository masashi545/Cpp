#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    // DPテーブル
    // dp[i+1][j]...
    vector<vector<int>> dp(n + 1, vector<int>(10001, INF));

    for (int i = n - 1; i >= 0; --i) {
        for (int u = 0; u <= W; ++u) {
            if (u < w[i]) {
                dp[i][u] = dp[i + 1][u];
            } else {
                dp[i][u] = max(dp[i + 1][u], dp[i + 1][u - w[i]] + v[i]);
            }
        }
    }
    return 0;
}