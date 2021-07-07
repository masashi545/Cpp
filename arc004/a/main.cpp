#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            int l = pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2);
            ans = max(ans, l);
        }
    }

    cout << fixed << setprecision(6) << sqrt(ans) << endl;
    return 0;
}