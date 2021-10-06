#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> G(r, vector<int>(c));
    rep(i, r) {
        rep(j, c) {
            cin >> G[i][j];
        }
    }

    int ans = 0;
    rep(tmp, 1 << r) {
        bitset<10> bs(tmp);

        int sum = 0;
        rep(j, c) {
            int x = 0;
            rep(i, r) {
                x += (G[i][j] + bs[i]) % 2; // 表の数を数える
            }
            sum += max(x, r - x); // その列を裏返した時(x)と、裏返さなかった時(r-x)の裏の数が大きい方をとる
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}