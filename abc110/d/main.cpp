#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;
using mint = modint1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    // cout << m << " = ";

    vector<P> a; // 各素因数の個数(累乗部分だけ保持すれば良い)
    // mを素因数に分解する
    for (int i = 2; i * i <= m; i++) {
        if (m % i != 0)
            continue;

        int p = 0;
        while (m % i == 0) {
            p++;
            m /= i;
        }
        a.push_back(P(i, p));
    }
    if (m != 1) {
        a.push_back(P(m, 1));
    }

    /*
    cout << a[0].first << "^" << a[0].second;
    rep(i, a.size() - 1) {
        cout << " + " << a[i + 1].first << "^" << a[i + 1].second;
    }
    cout << endl;
    */

    /*
    n個の箱に、素因数を入れていくことを考える
    例えば、n=3,m=12の場合、素因数は、12=2*2*3
    2を2個、3を1個、3つの箱に入れる組み合わせを考える
    2を入れる場合の数は、いずれか1つの箱に2個まとめて入れる3通り、いずれか2つの箱に1個ずつ入れる3通りで6通り
    3を入れる場合の和は、いずれか1つの箱に入れる3通り
    よって、6x3=18通り

    p個のある素因数(区別しない)を、n個の箱(区別する)に入れる場合の数は、p個のボールとn-1個の仕切りの並べ替え
    よって、(p+n-1)!/p!*(n-1)!=p+n-1Cp

    pは高々30 1<=p<=30
    n+1Cr+1=nCr+nCr+1
    */
    vector<mint> comb(31); // i+n-1Ci
    mint sub = n - 1;      // i+n-1Ci+1
    comb[0] = 1;
    for (int i = 1; i <= 30; i++) {
        comb[i] = comb[i - 1] + sub;
        sub = comb[i] * (n - 1) / (i + 1);
    }

    // rep(i, 31) cout << i << ":" << comb[i].val() << endl;

    mint ans = 1;
    rep(i, a.size()) {
        ans *= comb[a[i].second];
    }

    cout << ans.val() << endl;
    return 0;
}