#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // DPテーブル
    // dp[i][j]...i日目までに、j日間機嫌がよくなるように、ゲームに勝つ最低回数
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    rep(i, n) dp[i + 1][0] = 0;
    dp[1][1] = 1;

    int game = a[0]; // ゲーム回数（累積していく）
    for (int i = 1; i < n; ++i) {
        game += a[i];
        for (int j = 0; j <= i; ++j) {
            int k = dp[i][j];
            while (1) {
                k++;
                if (dp[i][j] * game < k * (game - a[i])) { // 勝率が高くなる最小の勝ち数ｋを求める
                    break;
                }
            }
            if (k - dp[i][j] <= a[i]) // その日の勝ち数が、その日のゲーム回数を超えなければOK
                dp[i + 1][j + 1] = k;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << "[" << i << "][" << j << "]:" << dp[i][j] << endl;
            if (dp[i][j] <= K && dp[i - 1][j - 1] + game >= K) {
                ans = max(ans, j);
            }
        }
        game -= a[i - 1]; // i+1日目以降の残りのゲーム回数
    }
    cout << ans << endl;

    return 0;
}