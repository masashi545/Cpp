#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;
ll const INF = 1e18 + 7;

int main() {
    int n;
    ll W;
    cin >> n >> W;
    vector<ll> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    // 前半分を全列挙する
    int n2 = n / 2;
    vector<P> ps(1 << n2);
    rep(tmp, 1 << n2) {
        bitset<20> bs(tmp);

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

    // 無駄な要素あ取り除く(重くなるにつれて価値が大きくなっているものだけを残す)
    // 以降、ps[0]~ps[idx-1]のみだけ考慮すれば良い
    sort(ps.begin(), ps.end());
    int idx = 1;
    for (int i = 1; i < 1 << n2; ++i) {
        if (ps[idx - 1].second < ps[i].second) {
            ps[idx++] = ps[i];
        }
    }

    // 後ろ半分を全列挙して解を求めていく
    ll ans = 0;
    rep(tmp, 1 << (n - n2)) {
        bitset<20> bs(tmp);

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
