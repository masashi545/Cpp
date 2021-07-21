#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    vector<ll> C(n);
    rep(i, n) cin >> C[i];

    vector<ll> ans(n);
    rep(i, n) {
        ll c = C[i];
        vector<int> x;
        while (c > 0) {
            x.push_back(c % 10);
            c /= 10;
        }

        ll res = 0;
        for (auto a : x) {
                }

        ans[i] = res;
    }
    return 0;
}