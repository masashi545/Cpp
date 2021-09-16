#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

// 最大公約数を求める-> O(log max{a,b})
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 最小公倍数を求める
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    cin >> n;
    ll l = 1;
    rep(i, n) {
        ll t;
        cin >> t;
        l = lcm(l, t);
    }

    cout << l << endl;
    return 0;
}