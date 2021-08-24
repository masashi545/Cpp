#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    string h = "Hello,World!";
    bool ok = (s.size() == 12);
    rep(i, 12) {
        if (s[i] != h[i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "AC" : "WA") << endl;
    return 0;
}