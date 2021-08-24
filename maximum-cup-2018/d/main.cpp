#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m, l, x;
    cin >> n >> m >> l >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // DPテーブル
    // dp[i+1][j]...i番目までの燃料タンクで休憩所jに停まるとき、最低周回数
    vector<vector<int>> dp(n + 1, vector<int>(m, INF));

    dp[0][0] = 0;
    rep(i, n) {
        rep(j, m) {
            if (dp[i][j] < INF) { // i-1番目までの燃料タンクでjに停まれる場合
                dp[i + 1][j] = dp[i][j];
            } else if (j >= a[i]) { // その周でlに停まれる場合
                dp[i + 1][j] = dp[i][j - a[i]];
            } else { // 1周以上してlに停まれる場合
                int k = 0;
                while (1) {
                    k++;
                    if (m * k + j - a[i] >= 0)
                        break;
                }
                dp[i + 1][j] = dp[i][m * k + j - a[i]] + k;
            }
        }
    }
    cout << ((dp[n][l] < x) ? "Yes" : "No") << endl;
    return 0;
}