#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = s; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, l, t;
    cin >> n >> l >> t;

    vector<ll> x(n), w(n);
    rep(i, 0, n) {
        cin >> x[i] >> w[i];
        if (w[i] == 1) {
            x[i] += t;
        } else {
            x[i] -= t;
        }
    }

    // x[0]にいるアリが何番目のアリなのかを計算
    ll num = 0; // x[0]にいるアリが、他のアリと時計回りの方向にすれ違った回数->時計回りにすれ違うと、indexが1大きいアリと入れ替わる->結局、最後にすれ違ったアリのindexが知りたい
    if (w[0] == 1) {
        rep(i, 1, n) {
            if (w[i] == 2) {
                num += (x[0] - x[i] + l - 1) / l; // 最終的に同じ場所の場合((x[0]-x[i]) % l == 0)は、＋しない
            }
        }
    }
    if (w[0] == 2) {
        rep(i, 1, n) {
            if (w[i] == 1) {
                num -= (x[i] - x[0]) / l;
            }
        }
    }
    num = ((num % n) + n) % n;

    // 位置を0〜l-1に
    rep(i, 0, n) x[i] = ((x[i] % l) + l) % l;

    // x[0]を保持 (x[0]の位置にいるのはnum番目のアリ)
    ll x0 = x[0];
    // cout << "x0 : " << x0 << endl;
    // cout << "num : " << num << endl;
    sort(x.begin(), x.end());
    auto itr = find(x.begin(), x.end(), x0);
    rotate(x.begin(), itr, x.end());                // まず、x[0]の位置にいるアリを先頭に
    rotate(x.rbegin(), x.rbegin() + num, x.rend()); // x[num]にもっていく

    rep(i, 0, n) cout << x[i] << endl;

    return 0;
}
