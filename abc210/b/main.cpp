#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool ans = true;
    for (char x : s) {
        if (x == '1') {
            break;
        }
        ans = !ans;
    }
    cout << (ans ? "Takahashi" : "Aoki") << endl;
    return 0;
}