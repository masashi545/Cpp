#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<int> prime;
vector<bool> is_prime(1000010, true);

// n以下の素数の数を返す
int sieve(int n) {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            // cout << i << endl;
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return prime.size();
}

int main() {
    int n;
    cin >> n;
    cout << sieve(n) << endl;
    return 0;
}

/*
in:
11

out:
5

in:
1000000

out:
78498
*/