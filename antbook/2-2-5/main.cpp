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
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    ll ans = 0;
    while (n > 1) {
        int i1 = 0; // 最も短い板
        int i2 = 1; // 次に短い板
        if (i1 > i2)
            swap(i1, i2);

        for (int i = 2; i < n; ++i) {
            if (l[i] < l[i1]) {
                i2 = i1;
                i1 = i;
            } else if (l[i] < l[i2]) {
                i2 = i;
            }
        }

        int t = l[i1] + l[i2]; // 併合コスト＝分割コスト
        ans += t;

        // 2つの板を1つの板に併合
        if (i1 == n - 1)
            swap(i1, i2);
        l[i1] = t;
        l[i2] = l[n - 1];
        n--;
    }

    cout << ans << endl;
    return 0;
}

/*
in:
3
8 5 8

out:
34
*/