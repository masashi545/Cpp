#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 入力
int n;
int p[100];

// DPテーブル
// dp[i+1][j]...i問目までの問題をいくつか解いた時の得点がjとなる場合の数
int dp[110][10010];

int main() {
    cin >> n;
    rep(i, n) cin >> p[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    rep(i, n) {
        rep(j, 10010) {
            dp[i + 1][j] += dp[i][j]; // i問目を解かないでjになる場合
            if (j >= p[i])
                dp[i + 1][j] += dp[i][j - p[i]]; // i問目を解いてjになる場合
        }
    }

    set<int> s;
    rep(i, 110) {
        rep(j, 10010) {
            if (dp[i][j] != 0)
                s.insert(j);
        }
    }
    cout << s.size() << endl;
    return 0;
}