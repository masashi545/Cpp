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
    vector<int> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];

    char pre = s[0];
    char now;
    bool first = true;

    int ans = 0;
    rep(i, m) {
        now = t[i];
        if (pre == now) {
            ans += 1;
        } else if (first) {
            int front = 0;
            int back = 0;
            rep(j, n) {
                if (s[j] != pre) {
                    front = j;
                    break;
                }
            }
            if (front == 0) {
                cout << -1 << endl;
                return 0;
            }

            rep(j, n) {
                if (s[j] != pre) {
                    back = j;
                }
            }
            int k = min(front, n - back);

            ans += k + 1;
            first = false;
        } else {
            ans += 2;
        }
        pre = now;
    }

    cout << ans << endl;
    return 0;
}