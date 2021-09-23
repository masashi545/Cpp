#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        ll n2, n3, n4;
        cin >> n2 >> n3 >> n4;

        // 4から使っていく
        ll ans = 0;
        if (n3 >= n4 * 2) {
            ans += n4;
            n3 -= n4 * 2;
            n4 = 0;
        } else {
            ans += ll(n3 / 2);
            n4 -= ll(n3 / 2);
            n3 %= 2;
        }

        if (n4 > 0) {
            if (n2 * 2 >= n4) {
                ans += ll(n4 / 2);
                n2 -= ll(n4 / 2);
                n4 %= 2;
                if (n4 > 0 && n2 >= 3) {
                    ans++;
                    n2 -= 3;
                }
            } else {
                ans += n2;
                cout << ans << endl;
                continue;
            }
        }
        // この時点で4は用済み

        // 3を使っていく
        if (n3 > 1) {
            if (n2 >= n3) {
                ans += ll(n3 / 2);
                n2 -= ll(n3 / 2) * 2;
                n3 %= 2;
            } else {
                ans += ll(n2 / 2);
                cout << ans << endl;
                continue;
            }
        }
        // この時点で3は用済み

        // 2を使っていく
        ans += ll(n2 / 5);
        cout << ans << endl;
    }
    return 0;
}