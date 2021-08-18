#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    vector<int> v(m);
    rep(i, m) cin >> v[i];

    int ans = 0;
    for (int i = m - 1; i >= 0; --i) {
        int t = n / v[i];
        n -= t * v[i];
        ans += t;
    }
    return 0;
}