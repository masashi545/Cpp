#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int k = 2; k <= n; ++k) {
        int m = k;
        for (int i = 2; i * i <= m; ++i) {
            while (m % i == 0) {
                mp[i]++;
                m /= i;
            }
        }
        if (m != 1)
            mp[m]++;
    }

    ll ans = 1;
    map<int, int>::iterator ite;
    for (ite = mp.begin(); ite != mp.end(); ++ite) {
        ans = (ans * (ite->second + 1)) % INF;
        // cout << ite->first << ": " << ite->second << endl;
    }

    cout << ans << endl;
    return 0;
}