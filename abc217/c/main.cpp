#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    vector<int> ans(n);
    rep(i, n) {
        ans[p[i] - 1] = i + 1;
    }

    rep(i, n) {
        if (i < n - 1) {
            cout << ans[i] << " ";
        } else {
            cout << ans[i] << endl;
        }
    }
    return 0;
}