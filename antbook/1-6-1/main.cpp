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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int len = a[i] + a[j] + a[k];
                int maxl = max({a[i], a[j], a[k]});
                int rest = len - maxl;

                if (maxl < rest) {
                    ans = max(ans, len);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
in:
5
2 3 4 5 10
out:
12

in:
4
4 5 10 20
out:
0
*/