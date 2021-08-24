#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int M;
    cin >> M;

    // DPテーブル
    // dp[i+1][j]...i番目までの品物からj個選ぶ組み合わせの数
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    rep(i, n) dp[i + 1][0] = 1; // i番目までの品物から0個選ぶ組み合わせは1通り

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j - 1 - a[i] >= 0) {
                dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - 1] - dp[i][j - 1 - a[i]] + M) % M;
            } else {
                dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - 1]) % M;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

/*
in:
3
3
1 2 3
10000

out:
6
*/