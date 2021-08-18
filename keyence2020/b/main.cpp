#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<P> range(n);
    rep(i, n) {
        int x, l;
        cin >> x >> l;
        range[i].first = x + l; // rangeの右端でソートしたいから
        range[i].second = x - l;
    }

    sort(range.begin(), range.end());

    int ans = 0;
    int end = -INF; // 残すと判断したロボットの右端
    rep(i, n) {
        if (end <= range[i].second) { // rangeの左端が、これまでに選んだロボットの右端より右にある場合、残す。
            ans++;
            end = range[i].first; // 右端を更新
        }
    }

    cout << ans << endl;
    return 0;
}