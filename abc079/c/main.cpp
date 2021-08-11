#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// char to int
int ctoi(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    return 0;
}

// true/false -> +/-
string pm(bool b) {
    if (b)
        return "+";
    else
        return "-";
}

int main() {
    string S;
    cin >> S;

    rep(tmp, 1 << 3) {
        bitset<3> s(tmp);

        int res = ctoi(S[0]);
        rep(i, 3) {
            if (s.test(i)) {
                res += ctoi(S[i + 1]);
            } else {
                res -= ctoi(S[i + 1]);
            }
        }

        if (res == 7) {
            cout << S[0];
            rep(i, 3) {
                cout << pm(s.test(i)) << S[i + 1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    return 0;
}