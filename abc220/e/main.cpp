#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;
ll const MOD = 998244353;

int main() {
    int n, d;
    cin >> n >> d;

    map<int, ll> mp;
    mp[0] = 1;
    ll k = 1;
    for (int i = 1; i < n; ++i) {
        mp[i] = k;
        mp[-i] = k;
        k = (k * 2) % MOD;
    }

    ll ans = 0;
    for (int i = -n + 1; i + d <= n - 1; ++i) {
        ans += (mp[i] * mp[i + d]) % MOD;
    }

    cout << ans << endl;
    return 0;
}