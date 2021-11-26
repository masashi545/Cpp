#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll a = 1; a * a * a <= N; ++a) {
        for (ll b = a; a * b * b <= N; ++b) {
            ans += N / (a * b) - b + 1;
        }
    }
    cout << ans << endl;
    return 0;
}