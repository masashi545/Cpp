#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    bool ok = true;
    bool flag = false;
    rep(i, n - 1) {
        if (s[i] == t[i]) {
            continue;
        }
        if (flag) {
            ok = false;
            break;
        }
        if (s[i + 1] == t[i] && s[i] == t[i + 1]) {
            flag = true;
            i++;
            continue;
        } else {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}