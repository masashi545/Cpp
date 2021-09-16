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

int main() {
    ll n, x;
    cin >> n >> x;
    ll g = gcd(n, x);
    n /= g;
    x /= g;

    ll ans = n - 1;
    ll a = n - x;
    ll b = x;
    if (a < b)
        swap(a, b);
    ll c;
    while (b > 0) {
        c = a % b;
        ans += (a - c) * 2;
        a = b;
        b = c;
    }

    ans *= g;

    cout << ans << endl;
    return 0;
}