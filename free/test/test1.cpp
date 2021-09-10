#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<string> ans(n);
    rep(i, n) {
        string s;
        cin >> s;
        ans[i] = "Hello," + s;
    }

    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}