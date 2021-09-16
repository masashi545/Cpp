#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    vector<int> prime;
    vector<bool> is_prime(100001, true);

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= 100000; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j <= 100000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> likenum(100001);
    int sum = 0;
    rep(i, 100001) {
        if (i % 2 == 1) {
            if (is_prime[i] && is_prime[(i + 1) / 2]) {
                sum++;
            }
        }
        likenum[i] = sum;
    }

    int q;
    cin >> q;
    vector<int> l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];

    rep(i, q) {
        cout << likenum[r[i]] - likenum[l[i] - 1] << endl;
    }
    return 0;
}