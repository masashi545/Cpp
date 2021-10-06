#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> d[i];

    vector<int> cd(n * n); // c + d の全列挙
    rep(i, n) {
        rep(j, n) {
            cd[i * n + j] = c[i] + d[j];
        }
    }

    sort(cd.begin(), cd.end());

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            int x = -(a[i] + b[j]);
            // 所望のxの値が配列cdにいくつあるか二分探索によって求める
            ans += upper_bound(cd.begin(), cd.end(), x) - lower_bound(cd.begin(), cd.end(), x);
        }
    }

    cout << ans << endl;
    return 0;
}

/*
in:
6
-45 -41 -36 -36 26 -32
22 -27 53 30 -38 -54
42 56 -37 -75 -10 -6
-16 30 77 -46 62 45

out:
5
*/