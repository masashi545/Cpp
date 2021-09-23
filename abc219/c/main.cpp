#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

map<char, int> m;
bool comp(string a, string b) {
    if (a.length() == 0) {
        return true;
    }
    if (b.length() == 0) {
        return false;
    }

    if (m[a[0]] == m[b[0]]) {
        return comp(a.substr(1), b.substr(1));
    }

    return m[a[0]] < m[b[0]];
}

int main() {
    string x;
    cin >> x;
    rep(i, 26) {
        m[x[i]] = i;
    }

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    sort(s.begin(), s.end(), comp);

    rep(i, n) cout << s[i] << endl;
    return 0;
}