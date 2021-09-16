#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    map<ll, set<ll>> mpx;
    map<ll, set<ll>> mpy;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v[i] = P(x, y);
        mpx[x].insert(y);
        mpy[y].insert(x);
    }

    int ans = 0;
    rep(i, n) {
        P p = v[i];
        mpx[p.first]
    }

    return 0;
}