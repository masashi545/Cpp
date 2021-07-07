#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int k, s;
    cin >> k >> s;

    int ans = 0;
    rep(i, k + 1) {
        rep(j, k + 1) {
            if (i + j <= s && s <= i + j + k)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}