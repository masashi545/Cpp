#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// x^n(mod)を求める
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) { // 最下位ビットが1だったら
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}