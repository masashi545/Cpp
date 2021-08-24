#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m, M;
    cin >> n >> m >> M;

    // DPテーブル
    // dp[i][j]...jのi分割の総数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}

/*
in:
4 3
10000
out:
4
*/