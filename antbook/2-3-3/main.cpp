#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    // DPテーブル
    // dp[i+1][j]...i番目までの品物から重さの総和がj以下になるように選んだ時の価値の最大値
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    // iについては一つ前のみ覚えておけばいいので、1次元のテーブルでもいい。

    rep(i, n) {
        rep(j, W + 1) {
            if (j < w[i]) { // i番目の品物を一つも選べない場合
                dp[i + 1][j] = dp[i][j];
            } else { // i番目の品物をいくつ選ぶか選択できる場合->2つ以上選ぶ場合は、他の場合に計算している。
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}

/*
in:
3 7
3 4
4 5
2 3
out:
10
*/