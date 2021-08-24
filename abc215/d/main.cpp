#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> a;
    rep(i, n) {
        int x;
        cin >> x;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                a.insert(j);
                a.insert(x / j);
            }
        }
        a.insert(x);
    }

    vector<bool> ans(m, true);
    for (auto k : a) {
        if (k == 1)
            continue;
        for (int j = 1; j * k <= m; j++) {
            ans[j * k - 1] = false;
        }
    }
    int sum = 0;
    rep(i, m) {
        if (ans[i])
            sum++;
    }
    cout << sum << endl;
    rep(i, m) {
        if (ans[i])
            cout << i + 1 << endl;
    }

    return 0;
}