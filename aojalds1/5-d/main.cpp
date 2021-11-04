#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

struct BIT {
    int m;
    vector<int> bit = {0}; // [1,n]

    void init(int n) {
        m = n;
        rep(i, m) bit.push_back(0);
    }

    // 1~iまでの和を求める
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i; // 最後の1のビットを引く
        }
        return s;
    }

    // iにxを足す
    void add(int i, int x) {
        while (i <= m) {
            bit[i] += x;
            i += i & -i; // 最後の1のビットを足す
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // 圧縮
    vector<int> xs(n);
    rep(i, n) xs[i] = a[i];
    sort(xs.begin(), xs.end());
    rep(i, n) a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

    BIT b;
    b.init(n);

    ll ans = 0;
    rep(j, n) {
        ans += j - b.sum(a[j]);
        b.add(a[j], 1);
    }

    cout << ans << endl;
    return 0;
}