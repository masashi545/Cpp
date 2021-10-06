#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int k;
    ll a, b;
    cin >> k >> a >> b;

    ll A = 0, B = 0;
    ll K = 1;
    while (a > 0) {
        A += (a % 10) * K;
        a /= 10;
        K *= k;
    }
    K = 1;
    while (b > 0) {
        B += (b % 10) * K;
        b /= 10;
        K *= k;
    }

    cout << A * B << endl;
    return 0;
}