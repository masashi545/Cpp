#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    vector<int> v(6), c(6);
    v = {1, 5, 10, 50, 100, 500};
    rep(i, 6) cin >> c[i];
    int a;
    cin >> a;

    int ans = 0;
    for (int i = 5; i >= 0; --i) {
        int t = min(a / v[i], c[i]); // コインを使う枚数
        a -= t * v[i];
        ans += t;
    }

    cout << ans << endl;
    return 0;
}

/*
in:
3 2 1 3 0 2
620

out:
6
*/