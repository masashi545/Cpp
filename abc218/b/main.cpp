#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    vector<int> p(26);
    rep(i, 26) cin >> p[i];

    rep(i, 26) {
        char x = 'a' + p[i] - 1;
        cout << x;
    }
    cout << endl;
    return 0;
}