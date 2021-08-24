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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    do {
        rep(i, n) cout << a[i] << " ";
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}