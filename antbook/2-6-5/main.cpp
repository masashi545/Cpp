#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<bool> is_prime(1000010, true);
vector<bool> is_prime_ab(1000010, true);

void segment_sieve(ll a, ll b) {
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 2; i * i < b; ++i) {
        if (is_prime[i]) {
            for (ll j = 2 * i; j * j < b; j += i) { // [2,√b)のふるい <- bまでの数の素因数は高々√bだから
                is_prime[j] = false;
            }
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) { // [a,b)のふるい
                is_prime_ab[j - a] = false;
            }
        }
    }
}

int main() {
    ll a, b;
    cin >> a >> b;

    segment_sieve(a, b);

    int ans = 0;
    rep(i, b - a) {
        if (is_prime_ab[i]) {
            ans++;
            // cout << a + i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
in:
22 37

out:
3

in:
22801763489 22801787297
*/