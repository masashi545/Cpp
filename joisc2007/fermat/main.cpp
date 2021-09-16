#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

// x^n(mod)を求める
int mod_pow(int x, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) { // 最下位ビットが1だったら
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int p, n;
    cin >> p >> n;
    map<int, int> count;
    rep(i, p) {
        count[mod_pow(i, n, p)]++;
    }
    /*for (auto ite = count.begin(); ite != count.end(); ++ite) {
        cout << ite->first << ": " << ite->second << endl;
    }*/

    // x^n + y^n ≡ 0 になる組み合わせの個数
    int zero = 0;
    rep(i, p) {
        zero += count[i] * count[(p - i) % p] * count[0];
    }
    // cout << zero << endl;

    // x^n + y^n ≡ 1 になる組み合わせの個数
    int one = 0;
    rep(i, p) {
        one += count[i] * count[(p - i + 1) % p] * count[1];
    }
    // cout << one << endl;

    // x^n (mod p)　の種類数を求める(0を除く)
    int sum = 0;
    for (int i = 1; i < p; ++i) {
        if (count[i] > 0)
            sum++;
    }
    // cout << sum << endl;

    cout << zero + one * sum << endl;
    return 0;
}