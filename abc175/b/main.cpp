#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = s; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, 0, n) cin >> l[i];

    sort(l.begin(), l.end());

    int ans = 0;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            rep(k, j + 1, n) {
                if (l[i] != l[j] && l[j] != l[k] && l[i] + l[j] > l[k]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}