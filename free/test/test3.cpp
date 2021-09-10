// C(GCC 9.2.1)

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> kaijyo(9);
    kaijyo[0] = 1;
    for (int i = 1; i < 9; ++i) {
        kaijyo[i] = kaijyo[i - 1] * i;
        cout << kaijyo[i] << endl;
    }

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        map<char, int> mp;
        for (char c : s[i]) {
            mp[c]++;
        }
        int ans = kaijyo[s[i].length()];
        map<char, int>::iterator ite;
        for (ite = mp.begin(); ite != mp.end(); ++ite) {
            ans /= kaijyo[ite->second];
        }
        cout << ans << endl;
    }

    return 0;
}