#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if (b - a < 0) {
        cout << 0 << endl;
    } else {
        cout << b - a + 1 << endl;
    }
    return 0;
}