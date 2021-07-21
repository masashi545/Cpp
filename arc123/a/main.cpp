#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = 0;
    // aとｃを固定
    if ((a + c) / 2 > b) {
        if ((a + c) % 2 == 0)
            ans = (a + c) / 2 - b;
        else
            ans = (a + c + 1) / 2 - b + 1;
    } else if ((a + c) / 2 < b) {
        ans = 2 * b - a - c;
    }

    cout << ans << endl;
    return 0;
}