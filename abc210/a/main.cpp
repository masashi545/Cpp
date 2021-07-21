#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, a, x, y;
    cin >> n >> a >> x >> y;

    if (n > a) {
        cout << x * a + y * (n - a) << endl;
    } else {
        cout << x * n << endl;
    }
    return 0;
}