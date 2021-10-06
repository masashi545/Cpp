#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;
ll const INF = 1e15 + 7;

int main() {
    int n;
    ll W;
    cin >> n >> W;
    vector<ll> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    ll vmax = 0;
    ll wmax = 0;
    rep(i, n) {
        vmax = max(vmax, v[i]);
        wmax = max(wmax, w[i]);
    }

    // DataSet1->半分全列挙で調べる
    if (n <= 30) {
        // 前半を全列挙する
        int n2 = n / 2;
        vector<P> ps(1 << n2);
        rep(tmp, 1 << n2) {
            bitset<15> bs(tmp);

            ll sw = 0;
            ll sv = 0;
            rep(i, n2) {
                if (bs.test(i)) {
                    sw += w[i];
                    sv += v[i];
                }
            }
            ps[tmp] = P(sw, sv);
        }

        // 無駄な要はは取り除く(重くなるにつれて価値が大きくなっているものだけを残す)
        // 以降、ps[0]~ps[idx-1]のみだけ考慮すれば良い
        sort(ps.begin(), ps.end());
        int idx = 1;
        for (int i = 1; i < 1 << n2; ++i) {
            if (ps[idx - 1].second < ps[i].second) {
                ps[idx++] = ps[i];
            }
        }

        // 後半を全列挙して解を求めていく
        ll ans = 0;
        rep(tmp, 1 << (n - n2)) {
            bitset<15> bs(tmp);

            ll sw = 0;
            ll sv = 0;
            rep(i, n - n2) {
                if (bs.test(i)) {
                    sw += w[n2 + i];
                    sv += v[n2 + i];
                }
            }
            if (sw <= W) {
                // 残りの重さ以下で価値が最大のものを選ぶ
                ll tv = (lower_bound(ps.begin(), ps.begin() + idx, P(W - sw, INF)) - 1)->second;
                ans = max(ans, sv + tv);
            }
        }

        cout << ans << endl;
        return 0;
    }

    // DataSet2->価値に関するDPで調べる
    else if (wmax <= 1000) {
        // DPテーブル
        // dp[i+1][j]...i番目までの品物から重さの総和がj以下になるように選んだ時の価値の最大値
        vector<vector<ll>> dp(n + 1, vector<ll>(200001, 0));

        rep(i, n) {
            rep(u, 200001) {
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

    // DataSet3->重さに関するDPで調べる
    else if (vmax <= 1000) {
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
                if (dp[i + 1][j] <= W) {
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