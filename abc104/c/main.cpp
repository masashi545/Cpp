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

    vector<queue<int>> que(d);
    rep(i, d) {
        rep(j, p[i] - 1) {
            que[i].push((i + 1) * 100);
        }
        que[i].push((i + 1) * 100 + c[i]);
    }

    int ans = 0;
    while (g > 0) {
        int maxp = 0; // 次に1問解いて得られる最大のポイント
        int prob = 0; // 選ぶ問題
        rep(i, d) {
            if (!que[i].empty() && maxp < que[i].front()) {
                maxp = que[i].front();
                prob = i;
            }
        }
        g -= maxp;
        que[prob].pop();
        ans++;
    }

    cout << ans << endl;
    return 0;
}