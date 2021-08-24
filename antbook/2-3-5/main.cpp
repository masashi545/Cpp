#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), m(n);
    rep(i, n) cin >> a[i] >> m[i];

    // DPテーブル
    // dp[i+1][j]...i番目の数まででjを作る際に余る最大のi番目の数
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    dp[0][0] = 0;
    rep(i, n) {
        rep(j, k + 1) {
            if (dp[i][j] >= 0) { // i-1番目の数まででjを作れる場合、 i番目の数は全て残すことができる
                dp[i + 1][j] = m[i];
            } else if (j < a[i] or dp[i + 1][j - a[i]] <= 0) { // i番目の数をいくつ使ってもjを作れない場合
                dp[i + 1][j] = -1;
            } else { // i番目の数を1つ以上使ってjを作れる場合
                dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
            }
        }
    }

    cout << ((dp[n][k] >= 0) ? "Yes" : "No") << endl;
    return 0;
}

/*
in:
3 17
3 3
5 2
8 2
out:
Yes
*/