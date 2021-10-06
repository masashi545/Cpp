#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    vector<int> a;
    while (n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    reverse(a.begin(), a.end());
    int m = a.size();

    // 桁DP
    // dp[i][smaller]..i桁目まで決めた時の暫定の答え
    // smaller = 0 -> Nより小さい場合
    // smaller = 1 -> Nと同じ場合
    vector<vector<int>> dp(m + 1, vector<int>(2));
    dp[0][0] = 0;
    rep(i, m) {
        rep(j, 2) {
            if (a[i] != 1) {
                dp[i + 1, j] = dp[i, j];
            }
        }
    }

    cout << dp[m][0] + dp[m][1] << endl;
    return 0;
}