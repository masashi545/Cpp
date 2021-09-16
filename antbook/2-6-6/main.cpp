#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return n != 1;
}

int main() {
    int n;
    cin >> n;

    if (is_prime(n)) {
        cout << "No(prime)" << endl;
        return 0;
    }

    for (int x = 2; x < n; ++x) {
        ll ans = mod_pow(x, n, n);
        if (ans != x) {
            cout << "No(" << x << "^" << n << "=" << ans << ")" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}