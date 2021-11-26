#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int s, t, x;
    cin >> s >> t >> x;
    if (s < t) {
        cout << ((s <= x && x < t) ? "Yes" : "No") << endl;
    } else {
        cout << ((x < t || s <= x) ? "Yes" : "No") << endl;
    }
    return 0;
}