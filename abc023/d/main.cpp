#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
ll const INF = 1e15 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> h(n), s(n);
    rep(i, n) cin >> h[i] >> s[i];

    ll lb = 0;
    ll ub = INF;

    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        // 全ての風船を高度mid以下で撃ち落とすことができるか判定
        bool ok = true;
        vector<ll> c(n);
        rep(i, n) {
            c[i] = (mid - h[i]) / s[i];
            if (mid < h[i])
                ok = false;
        }

        sort(c.begin(), c.end());

        rep(i, n) {
            if (i > c[i])
                ok = false;
        }
        if (ok)
            ub = mid;
        else
            lb = mid;
        // cout << "lb=" << lb << ", ub=" << ub << endl;
    }

    cout << ub << endl;
    return 0;
}