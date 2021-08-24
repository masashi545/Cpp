#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    // 最長増加部分列の長さを求める

    // DPテーブル
    // dp[i]...長さがi+1であるような増加部分列における最終要素の最小値(ないばあいはINF)
    vector<int> dp(n, INF);

    // 最終要素ができるだけ小さい方が有利
    rep(j, n) {                                                       // a[j]を新しく考慮する
        int i = lower_bound(dp.begin(), dp.end(), c[j]) - dp.begin(); // a[j]より大きい初めての要素だけをa[j]に更新する
        /*
        int i = 0;
        while (dp[i] < a[j]) {
            i++;
        }
        */
        dp[i] = min(dp[i], c[j]);
    }

    int res = 0; // 最長増加部分列の長さ
    rep(i, n) {
        if (dp[i] < INF) {
            res = max(res, i + 1);
        }
    }
    cout << n - res << endl;
    return 0;
}