#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<ll> b_count(n);
    ll sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += c.end() - upper_bound(c.begin(), c.end(), b[i]);
        b_count[i] = sum;
    }
    ll ans = 0;
    rep(i, n) {
        int ite = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans += b_count[ite];
    }

    cout << ans << endl;
    return 0;
}