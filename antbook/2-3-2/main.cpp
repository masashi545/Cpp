#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    // DPテーブル
    // dp[i][j]...s1~siと,t1~tjに対するLCSの長さ
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    rep(i, n) {
        rep(j, m) {
            if (s[i] == t[j]) { // 次の文字が同じだったら、LCSを伸ばせる
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else { // 次の文字が違ったら、それまでの文字列でのLCSで長い方をとる
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

/*
in:
4 4
abcd
becd
out: 
3
*/