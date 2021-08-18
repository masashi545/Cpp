#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int a;
    cin >> a;
    vector<int> v(6);
    v = {500, 100, 50, 10, 5, 1};

    a = 1000 - a; // お釣りを求める
    int ans = 0;
    rep(i, 6) {
        int t = a / v[i];
        a -= t * v[i];
        ans += t;
    }

    cout << ans << endl;
    return 0;
}