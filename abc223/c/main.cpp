#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    cout << fixed << setprecision(15);

    double sum = 0;
    rep(i, n) sum += a[i] / b[i];
    sum /= 2.0;

    double t = 0;
    int m = 0;
    double ts;
    while (true) {
        if (t + a[m] / b[m] >= sum) {
            ts = sum - t;
            break;
        }
        t += a[m] / b[m];
        m++;
    }

    double ans = 0;
    rep(i, m) {
        ans += a[i];
    }
    ans += ts * b[m];

    cout << ans << endl;
    return 0;
}