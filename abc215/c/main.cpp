#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    vector<char> a(n);
    rep(i, n) a[i] = s[i];

    sort(a.begin(), a.end());

    k--;
    while (k--) {
        next_permutation(a.begin(), a.end());
    }

    rep(i, n) cout << a[i];
    cout << endl;
    return 0;
}