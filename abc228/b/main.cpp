#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> known(n, false);
    int idx = x - 1;
    known[idx] = true;
    while (!known[a[idx]]) {
        known[a[idx]] = true;
        idx = a[idx];
    }

    int ans = 0;
    rep(i, n) {
        if (known[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}