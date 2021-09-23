#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, q) {
        ll x;
        cin >> x;

        ll ans = 0;
        int l = 0, r = 0;
        ll sum = 0;
        while (true) {
            while (r < n && sum + a[r] <= x) {
                sum += a[r++];
            }
            ans += r - l;
            // cout << "l=" << l << ", r=" << r << endl;
            sum -= a[l++];
            if (l >= n)
                break;
        }

        cout << ans << endl;
    }

    return 0;
}