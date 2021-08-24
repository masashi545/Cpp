#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
ll const INF = 1e12 + 7;

int n;
ll W;
vector<int> v, w;

ll search(int i, ll u) { // i番目以降の品物から重さの総和がu以下になるように選んだ時の最大の価値を返す
    if (i == n) {        // 品物は残っていないので、得られる価値なし
        return 0;
    } else if (u < w[i]) { // この品物は入らないので、次以降の品物について調べる
        return search(i + 1, u);
    } else { // この品物を入れない場合と、入れる場合でコストが大きくなる方を選ぶ
        return max(search(i + 1, u), search(i + 1, u - w[i]) + v[i]);
    }
}

int main() {
    cin >> n >> W;
    w.resize(n);
    v.resize(n);
    rep(i, n) cin >> v[i] >> w[i];

    bool v1000 = true;
    bool w1000 = true;
    rep(i, n) {
        if (v[i] > 1000)
            v1000 = false;
        if (w[i] > 1000)
            w1000 = false;
    }

    // 全探索で調べる
    if (n <= 30) {
        cout << search(0, W) << endl;
        return 0;
    }
    // 価値に関するDPで調べる
    else if (w1000) {
        // DPテーブル
        // dp[i+1][j]...i番目までの品物から重さの総和がj以下になるように選んだ時の価値の最大値
        vector<vector<ll>> dp(n + 1, vector<ll>(200001, 0));

        rep(i, n) {
            rep(u, 200000) {
                if (u < w[i]) {
                    dp[i + 1][u] = dp[i][u];
                } else {
                    dp[i + 1][u] = max(dp[i][u], dp[i][u - w[i]] + v[i]);
                }
            }
        }

        cout << dp[n][W] << endl;
        return 0;
    }

    // 重さに関するDPで調べる
    else if (v1000) {
        // DPテーブル
        // dp[i+1][j]...i番目までの品物から価値の総和がjになるように選んだ時の重さの最小値
        vector<vector<ll>> dp(n + 1, vector<ll>(200001, INF));
        dp[0][0] = 0;

        rep(i, n) {
            rep(u, 200001) {
                if (u < v[i]) {
                    dp[i + 1][u] = dp[i][u];
                } else {
                    dp[i + 1][u] = min(dp[i][u], dp[i][u - v[i]] + w[i]);
                }
            }
        }
        int ans = 0;
        rep(i, n) {
            rep(j, 200001) {
                if (dp[i][j] <= W) {
                    ans = max(ans, j);
                }
            }
        }
        cout << ans << endl;
        return 0;
    } else {
        cout << "error" << endl;
        return 0;
    }

    return 0;
}