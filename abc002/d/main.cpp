#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        G[x - 1].push_back(y - 1);
        G[y - 1].push_back(x - 1);
    }

    int ans = 0;
    rep(i, 1 << n) {
        bitset<12> bs(i); // 1である人を派閥として考える。全員互いに知り合いであれば派閥成立

        bool b = true; // 全員互いに知り合いであるか否か
        vector<int> f; // 派閥に入っている人
        rep(j, n) {
            if (bs.test(j)) {      // 派閥に入ろうとする人が
                rep(k, f.size()) { // 現在派閥に入っている人全員と知り合いかどうか
                    if (find(G[j].begin(), G[j].end(), f[k]) == G[j].end()) {
                        b = false;
                        break;
                    }
                }
                if (!b) {
                    break;
                }
                f.push_back(j);
            }
        }

        if (b) {
            ans = max(ans, int(f.size()));
        }
    }
    cout << ans << endl;
    return 0;
}