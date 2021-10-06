#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

vector<int> a;
int m;

int solve(int d) {
    int x = 0, y = 0;
    int k = 1;
    rep(i, d) {
        x += a[i] * k;
        k *= 10;
    }
    k = 1;
    for (int i = d; i < m; ++i) {
        y += a[i] * k;
        k *= 10;
    }
    // cout << "x=" << x << endl;
    // cout << "y=" << y << endl;
    return x * y;
}

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    m = a.size();
    sort(a.begin(), a.end());

    int ans = 0;
    do {
        rep(i, m - 1) {
            ans = max(ans, solve(i + 1));
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << endl;
    return 0;
}