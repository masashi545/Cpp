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
    ll num = 0;
    if (w[0] == 1) {
        rep(i, 1, n) {
            if (w[i] == 2) {
                num += (x[0] - x[i] + l - 1) / l; // すれ違う回数　最終的に同じ場所の場合((x[0]-x[i]) % l == 0)は、＋しない
            }
        }
    }
    if (w[0] == 2) {
        rep(i, 1, n) {
            if (w[i] == 1) {
                num -= (x[i] - x[0]) / l; // すれ違う回数
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
    rotate(x.begin(), itr, x.end());
    rotate(x.rbegin(), x.rbegin() + num, x.rend());

    rep(i, 0, n) cout << x[i] << endl;

    return 0;
}