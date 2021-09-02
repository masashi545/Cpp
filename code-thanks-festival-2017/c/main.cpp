#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;
int const INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i, n) {
        P p;
        cin >> p.first >> p.second;
        que.push(p);
    }

    ll ans = 0;
    while (k--) {
        P p = que.top();
        que.pop();
        ans += p.first;
        p.first += p.second;
        que.push(p);
    }

    cout << ans << endl;
    return 0;
}