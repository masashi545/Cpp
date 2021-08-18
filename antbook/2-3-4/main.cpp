#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    // DPテーブル
    // dp[i+1][j]...i番目までの品物から価値の総和がjになるように選んだ時の重さの最小値
    vector<vector<int>> dp(n + 1, vector<int>(10001, INF));
    dp[0][0] = 0;

    rep(i, n) {
        rep(u, 10001) {
            if (u < v[i]) {
                dp[i + 1][u] = dp[i][u];
            } else {
                dp[i + 1][u] = min(dp[i][u], dp[i][u - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        rep(j, 10001) {
            if (dp[i][j] <= W) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
in:
4 5
2 3
1 2
3 4
2 2
out:
7
*/