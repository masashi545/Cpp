#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    // DPテーブル
    // dp[i+1][j]...i番目までの魔法を使って、モンスターの体力をj以上削る時の魔力の最小値
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, INF));
    dp[0][0] = 0;

    rep(i, n) {
        rep(j, h + 1) {
            if (j < a[i]) { // i番目の魔法を使うだけでj以上削ってしまう場合
                dp[i + 1][j] = min(dp[i][j], b[i]);
            } else { // i番目の魔法を何回か使ってj以上削る場合->2回以上使う場合は、他の場合で計算している。
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}