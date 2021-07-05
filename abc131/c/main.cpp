#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // 10^10以上を扱う時は、long long

// 最小公約数
ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

// 最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// 区間[1,R]で、divで割った余りがmodとなるものの個数
ll countMultiple(ll R, ll div, ll mod) {
    if (R == 0)
        return 0;

    ll res = R / div;
    if (0 < mod && mod <= R % div)
        res++;

    return res;
}

ll A, B, C, D;

// 区間[1,x]でCでもDでも割り切れない数の個数を返す
ll f(ll x) {
    if (x == 0)
        return 0;

    ll lc = lcm(C, D);
    return x - (countMultiple(x, C, 0) + countMultiple(x, D, 0) - countMultiple(x, lc, 0));
}

int main() {
    cin >> A >> B >> C >> D;

    // 区間[A,B]での個数は、([1,B]での個数)ー([1,A-1]での個数
    cout << f(B) - f(A - 1) << endl;
}