#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];

    g /= 100;
    for (auto &x : c)
        x /= 100;

    int ans = INF;
    rep(i, 1 << d) {
        bitset<10> bs(i); // ビットが1である問題を全て解くとする
        int sum = g;      // スコア
        int cnt = 0;      // 問題数

        // 全て解く問題について、スコアを引き、問題数を足す
        rep(j, 10) {
            if (bs.test(j)) {
                sum -= (j + 1) * p[j] + c[j];
                cnt += p[j];
            }
        }

        // スコアが0以下になるまで、残っている問題で、最も点数の高い問題を解く
        int j = d - 1; // ｊ：残っている問題で、最も点数の高い問題
        while (j >= 0 && bs.test(j)) {
            j--;
        }
        if (j < 0 || sum <= 0) { // 残っている問題がない、またはこの時点でスコアが0以下になっている場合は、終了
            ans = min(ans, cnt);
            continue;
        }

        bool clear = false;
        rep(k, p[j] - 1) { //　全部解くまでにスコアが0以下になればOK
            sum -= j + 1;
            cnt++;
            if (sum <= 0) {
                clear = true;
                break;
            }
        }

        if (clear) {
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}