#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];

    g /= 100;
    for (auto &x : c)
        x /= 100;

    vector<vector<int>> pp(d); // 問題iをj問解いた時の点数
    rep(i, d) {
        vector<int> d(p[i] + 1);
        rep(j, p[i] + 1) {
            d[j] = (i + 1) * j;
        }
        d[p[i]] += c[i];

        pp[i] = d;
    }

    int ans = 0;
    while (1) {
        int maxp = 0;
        int tmp = ans;
        while (maxp < g) {
            rep(i, d) {
                if (tmp <= p[i]) { // 回答数が問題数以下の場合は、配列を参照できる
                    maxp = max(maxp, pp[i][tmp]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}