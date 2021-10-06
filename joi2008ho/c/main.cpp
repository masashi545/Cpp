#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    rep(i, n) cin >> p[i];
    p[n] = 0; // 投げない

    vector<int> pp((n + 1) * (n + 1));
    rep(i, n + 1) {
        rep(j, n + 1) {
            pp[i * (n + 1) + j] = p[i] + p[j];
        }
    }
    sort(pp.begin(), pp.end());

    int ans = 0;
    rep(i, (n + 1) * (n + 1)) {
        int x = m - pp[i];
        if (x < 0) {
            break;
        }
        int idx = lower_bound(pp.begin(), pp.end(), x) - pp.begin();
        if (pp[idx] > x)
            idx--;
        ans = max(ans, pp[i] + pp[idx]);
    }

    cout << ans << endl;
    return 0;
}