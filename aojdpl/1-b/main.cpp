#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    // DPテーブル
    // dp[i+1][j]...i番目以降の品物から重さの総和がj以下になるように選んだ時の価値の最大値
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = n - 1; i >= 0; --i) {
        for (int u = 0; u <= W; ++u) {
            if (u < w[i]) {
                dp[i][u] = dp[i + 1][u];
            } else {
                dp[i][u] = max(dp[i + 1][u], dp[i + 1][u - w[i]] + v[i]);
            }
        }
    }

    cout << dp[0][W] << endl;
    return 0;
}