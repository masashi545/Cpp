#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    sort(x.begin(), x.end());

    int i = 0;
    int ans = 0;
    while (i < n) {
        int s = x[i++];                // カバーされていない最左の点の位置
        while (i < n && x[i] <= s + r) // sからr以内の最も遠い点を見つける
            i++;

        int p = x[i - 1];              // 印をつける点の位置
        while (i < n && x[i] <= p + r) // カバーできない点を見つける
            i++;

        ans++;
    }

    cout << ans << endl;
    return 0;
}

/*
in:
6
10
1 7 15 20 30 50

out:
3
*/