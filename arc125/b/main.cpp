#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using ld = long double;
using P = pair<int, int>;
int const INF = 1e9 + 7;
int const MOD = 998244353;

int main() {
    ll n;
    cin >> n;

    ll k = 0;

    ll ans = 0;
    for (ll q = 1; q * q <= n; q++) {
        ll sum = ll(n / q) - q + 1;
        ans += ll(sum / 2);
        if (sum % 2) {
            ans++;
        }
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}