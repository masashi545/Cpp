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
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, n) {
        int a;
        cin >> a;
        que.push(a);
    }

    ll ans = 0;
    ll times = 2;
    while (que.size() > 1) {
        ans += times * que.top(); // 最小の数を順に取り出していくのが最適
        que.pop();
        times++;
    }
    ans += (times - 1) * que.top();

    cout << ans << endl;
    return 0;
}