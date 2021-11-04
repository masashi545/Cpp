#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    string mins = s;
    string maxs = s;
    rep(i, n - 1) {
        string tmp = s.substr(i + 1, n - i - 1) + s.substr(0, i + 1);
        mins = min(mins, tmp);
        maxs = max(maxs, tmp);
    }
    cout << mins << endl;
    cout << maxs << endl;
    return 0;
}