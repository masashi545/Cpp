#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string x, y;
        cin >> x >> y;
        int n = x.length();
        int m = y.length();

        // DPテーブル
        // dp[i][j]...x1~xiと,y1~yjに対するLCSの長さ
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        rep(i, n) {
            rep(j, m) {
                if (x[i] == y[j]) { // 次の文字が同じだったら、LCSを伸ばせる
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else { // 次の文字が違ったら、それまでの文字列でのLCSで長い方をとる
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}

/*
in:
3
abcbdab
bdcaba
abc
abc
abc
bc
out:
4
3
2
*/