#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int l, n;
    cin >> l >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    int mint = 0;
    int maxt = 0;

    rep(i, n) {
        mint = max(mint, min(x[i], l - x[i]));
        maxt = max(maxt, max(x[i], l - x[i]));
    }

    cout << mint << endl;
    cout << maxt << endl;
    return 0;
}

/*
in:
10
3
2 6 7
out:
mint = 4
maxt = 8
*/