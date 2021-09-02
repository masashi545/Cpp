#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int m;
    cin >> m;
    rep(i, m) {
        string t;
        cin >> t;
        mp[t]--;
    }

    int ans = 0;
    map<string, int>::iterator ite;
    for (ite = mp.begin(); ite != mp.end(); ++ite) {
        ans = max(ans, ite->second);
    }

    cout << ans << endl;
    return 0;
}