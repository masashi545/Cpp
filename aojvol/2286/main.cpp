#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    vector<int> prime;
    vector<bool> is_prime(1000001, true);

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= 1000000; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    rep(i, n) {
        ll ans = n + 1;
    }
    return 0;
}