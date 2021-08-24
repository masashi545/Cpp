#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    int k = 0;
    ll p = 2;
    while (p <= n) {
        k++;
        p *= 2;
    }

    cout << k << endl;
    return 0;
}