#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    set<pair<string, string>> s;
    rep(i, n) {
        pair<string, string> x;
        cin >> x.first >> x.second;
        s.insert(x);
    }

    if (n > s.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}