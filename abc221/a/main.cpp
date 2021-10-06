#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    a -= b;
    ll ans = 1;
    while (a--) {
        ans *= 32;
    }

    cout << ans << endl;
    return 0;
}