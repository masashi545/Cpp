#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using modint = atcoder::modint1000000007;

typedef long long ll;

/* スタックオーバーフロー
modint nCr(int n, int r) {
    if (n == r || r == 0) {
        return 1;
    } else {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
} */

modint nCr(int n, int r) {
    if (n < 0 || r < 0 || n < r)
        return 0;

    modint res = 1;
    for (int i = n; i > n - r; i--)
        res *= i;
    for (int i = 1; i <= r; i++)
        res /= i;
    return res;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    if (N > M + K) {
        cout << 0 << endl;
    } else {
        cout << (nCr(N + M, N) - nCr(N + M, M + K + 1)).val() << endl;
    }
    return 0;
}