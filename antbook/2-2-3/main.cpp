#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0;
    int r = n - 1;
    string t = "";
    while (l <= r) {
        bool left = false;
        for (int i = 0; l + i <= r; ++i) {
            if (s[l + i] < s[r - i]) {
                left = true;
                break;
            } else if (s[l + i] > s[r - i]) {
                left = false;
                break;
            }
        }
        if (left)
            t += s[l++];
        else
            t += s[r--];
        cout << t << endl;
    }

    return 0;
}

/*
in:
6
ACDBCB

out:
ABCBCD
*/