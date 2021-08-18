#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll x, y;
    cin >> x >> y;
    int ans = 0;
    while (x <= y) {
        ans++;
        x *= 2; // 2倍の数を入れていくのが最適
    }

    cout << ans << endl;
    return 0;
}