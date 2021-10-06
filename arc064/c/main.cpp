#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(i, n - 1) {
        if (a[i] + a[i + 1] <= x) {
            continue;
        } else if (a[i] <= x) {
            ans += a[i] + a[i + 1] - x;
            a[i + 1] = x - a[i];
        } else {
            ans += a[i] + a[i + 1] - x;
            a[i] = x;
            a[i + 1] = 0;
        }
    }

    cout << ans << endl;
    return 0;
}