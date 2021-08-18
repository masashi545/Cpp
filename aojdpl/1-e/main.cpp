#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    // DPテーブル
    // dp[i][j]...s1~siと,t1~tjに対するLCSの長さ
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n) dp[i + 1][0] = i + 1;
    rep(j, m) dp[0][j + 1] = j + 1;

    rep(i, n) {
        rep(j, m) {
            if (s[i] == t[j]) { // 次の文字が同じだったら、操作は不要
                dp[i + 1][j + 1] = dp[i][j];
            } else { // 次の文字が違ったら、s[i+1]をt[j+1]に置換操作、またはsにt[j+1]を追加操作、またはtにs[i+1]を追加操作
                dp[i + 1][j + 1] = min({dp[i][j] + 1, dp[i][j + 1] + 1, dp[i + 1][j] + 1});
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}