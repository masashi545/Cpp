#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll x;
    cin >> x;

    vector<ll> sum(n + 1, 0);
    rep(i, n) {
        sum[i + 1] = sum[i] + a[i];
    }

    ll k = x / sum[n];
    ll rest = x - sum[n] * k;

    ll ans = k * n;
    ans += upper_bound(sum.begin(), sum.end(), rest) - sum.begin();

    cout << ans << endl;
    return 0;
}