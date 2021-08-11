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
    vector<int> t(4, 0);
    rep(i, n) cin >> t[i];

    int sum = t[0] + t[1] + t[2] + t[3];
    int maxt = max({t[0], t[1], t[2], t[3]});
    int mint = min({t[0], t[1], t[2], t[3]});
    int one = max(maxt, sum - maxt);
    int two = max(maxt + mint, sum - maxt - mint);
    cout << min(one, two) << endl;

    return 0;
}