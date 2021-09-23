#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main1() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // sum[i]...aのi項より前の和を計算する
    vector<int> sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] + a[i];

    if (sum[n] < s) {
        cout << 0 << endl;
        return 0;
    }

    int ans = n;
    for (int l = 0; sum[l] + s <= sum[n]; ++l) {
        // 終端rを二分探索で求める
        int r = lower_bound(sum.begin() + l, sum.end(), sum[l] + s) - sum.begin();
        ans = min(ans, r - l);
    }

    cout << ans << endl;
    return 0;
}

// しゃくとり法
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = n + 1;
    int l = 0, r = 0, sum = 0;
    while (true) {
        while (r < n && sum < s) {
            sum += a[r++];
        }
        if (sum < s)
            break;
        ans = min(ans, r - l);
        sum -= a[l++];
    }

    if (ans > n) {
        ans = 0;
    }

    cout << ans << endl;
}

/*
in:
10
15
5 1 3 5 10 7 4 9 2 8

out:
2

in:
5
11
1 2 3 4 5

out:
3
*/