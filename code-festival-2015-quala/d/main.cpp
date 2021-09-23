#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];

    ll lb = -1;
    ll ub = n * 2;

    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        // mid分以内で終わらせられるか判定
        ll finish = 0; // ここまで点検できてる
        rep(i, m) {
            ll a = x[i] - finish - 1;
            if (a < 0) {
                finish = x[i] + mid;
                continue;
            }
            if (mid - a < 0) {
                break;
            }
            ll b = max(mid - 2 * a, (mid - a) / 2);
            finish = x[i] + b;
        }

        if (finish >= n)
            ub = mid;
        else
            lb = mid;
        // cout << "lb=" << lb << ", ub=" << ub << endl;
    }

    cout << ub << endl;
    return 0;
}