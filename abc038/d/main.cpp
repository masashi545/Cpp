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
    vector<P> box(n);
    rep(i, n) {
        cin >> box[i].first >> box[i].second;
    }

    // 最長増加部分列の長さを求める

    // DPテーブル
    // dp[i]...長さがiであるような増加部分列における最終要素の最小値(ないばあいはINF)
    vector<P> dp(n, P(INF, INF));

    // 最終要素ができるだけ小さい方が有利
    rep(i, n) { // box[j]を新しく考慮する
        int l = -1;
        int r = n;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (dp[mid].first >= box[i].first && dp[mid].second >= box[i].second) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (i == 0 or (dp[i - 1].first < box[j].first && dp[i - 1].second < box[j].second)) {
            dp[i] = box[j];
        }
    }

    int res = 0; // 最長増加部分列の長さ
    rep(i, n) {
        cout << "dp[" << i << "]:" << dp[i].first << " " << dp[i].second << endl;
        if (dp[i] < P(INF, INF)) {
            res = max(res, i + 1);
        }
    }
    cout << res << endl;
    return 0;
}