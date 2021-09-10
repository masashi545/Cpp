#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    vector<string> s(4);
    s = {"ABC", "ARC", "AGC", "AHC"};
    rep(i, 3) {
        string x;
        cin >> x;
        if (x == "ABC")
            s[0] = "";
        if (x == "ARC")
            s[1] = "";
        if (x == "AGC")
            s[2] = "";
        if (x == "AHC")
            s[3] = "";
    };
    rep(i, 4) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}