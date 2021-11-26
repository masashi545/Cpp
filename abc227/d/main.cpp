#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> v(N);
    rep(i, N) cin >> v[i];

    ll ok = 0;
    ll ng = 1e18 / K;
    while (ng - ok > 1) {
        ll md = (ok + ng) / 2;
        // md個プロジェクトを作ることが可能かを調べる
        ll sum = 0; // いずれかのプロジェクトに参加する人数
        rep(i, N) {
            sum += min(v[i], md);
        }
        if (sum >= K * md) { // 可能
            ok = md;
        } else { // 不可能
            ng = md;
        }
    }

    cout << ok << endl;
    return 0;
}