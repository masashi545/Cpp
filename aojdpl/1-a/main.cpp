#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i, m) cin >> c[i];

    // DPテーブル
    // dp[i+1][j]...i番目までのコインを使ってj円を支払う時のコインの最小枚数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;

    rep(i, m) {
        rep(j, n + 1) {
            if (j < c[i]) { // i番目のコインを使うとj円を超えてしまう場合、使わない
                dp[i + 1][j] = dp[i][j];
            } else { // i番目のコインを1枚も使わない場合と、1枚以上使う場合について枚数が少ない方を選択
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - c[i]] + 1);
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}