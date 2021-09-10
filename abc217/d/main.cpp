#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    ll l;
    int q;
    cin >> l >> q;

    set<ll> cut;
    cut.insert(0);
    cut.insert(l);

    rep(i, q) {
        int c;
        ll x;
        cin >> c >> x;

        if (c == 1) {
            cut.insert(x);
        } else {
            auto itr = cut.lower_bound(x);
            cout << (*itr - *prev(itr)) << endl;
        }
    }

    return 0;
}