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

    // DPテーブル
    // dp[i]...i番目の要素までの最長増加部分列
    vector<int> dp(n, 0);

    int res = 0;
    rep(i, n) {
        dp[i] = 1;
        rep(j, i) {            // i番目までの要素で、a[i]よりも小さい要素a[j]があった場合
            if (a[j] < a[i]) { // j番目までの要素の増加部分列にa[i]を後ろから連結することで増加部分列を作れる
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;
    return 0;
}

/*
in:
5
4 2 3 1 5
out:
3
*/