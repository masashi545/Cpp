#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll s;
    cin >> s;
    vector<int> a;
    while (s > 0) {
        a.push_back(s % 10);
        s /= 10;
    }
    int n = a.size();

    ll ans = 0;
    rep(tmp, 1 << (n - 1)) {
        bitset<9> s(tmp);

        ll sum = a[0];
        int k = 1;
        rep(i, n - 1) {
            if (s.test(i)) {
                k = 0;
            }
            sum += a[i + 1] * pow(10, k);
            k++;
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}