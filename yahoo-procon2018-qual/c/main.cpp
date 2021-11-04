#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e18 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> sumx(n + 1), c(n), v(n);
    rep(i, n) {
        ll x;
        cin >> x;
        sumx[i + 1] = sumx[i] + x;
    }
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> v[i];

    // dp[S][v]..S：青木くんが残している商品集合, v:高橋くんが購入した商品の数
    // この状態において、高橋くんが得られる最大の価値
    vector<vector<ll>> dp(1 << n, vector<ll>(n + 1, INF));

    dp[(1 << n) - 1][0] = 0;
    ll ans = INF;
    for (int S = (1 << n) - 1; S >= 0; --S) {
        int v = 0; // 高橋くんがどこまで売ったか
        rep(i, n) {
            if (S >> i & 1)
                v++;
        }
        ll money = sumx[v]; // 高橋くんの所持金
    }

    return 0;
}