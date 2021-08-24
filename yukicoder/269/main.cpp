#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, s, k;
    cin >> n >> s >> k;

    int m = s - (n - 1) * n * k / 2; // ちょうどK円ずつ上げていった場合に残る金額をn人で分割する
    if (m < 0) {
        cout << 0 << endl;
        return 0;
    }

    // DPテーブル
    // dp[i][j]...jのi分割の総数
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % INF;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}