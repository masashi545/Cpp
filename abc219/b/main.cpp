#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    string t;
    cin >> t;

    for (char x : t) {
        if (x == '1')
            cout << s[0];
        if (x == '2')
            cout << s[1];
        if (x == '3')
            cout << s[2];
    }

    cout << endl;
    return 0;
}