#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // しゃくとり法
    int l = 0, r = 0;
    set<int> s;
    int ans = 0;
    while (true) {
        while (r < n && !s.count(a[r])) {
            s.insert(a[r]);
            r++;
        }

        ans = max(ans, r - l);
        // cout << "l=" << l << ", r=" << r << endl;
        if (r == n)
            break;
        while (s.count(a[r])) {
            s.erase(a[l]);
            l++;
        }
    }

    cout << ans << endl;
    return 0;
}