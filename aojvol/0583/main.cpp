#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a, b, c;
    int g;
    vector<int> ans;

    if (n == 2) {
        cin >> a >> b;
        g = gcd(a, b);
        ans = divisor(g);
    } else {
        cin >> a >> b >> c;
        g = gcd(gcd(a, b), c);
        ans = divisor(g);
    }

    sort(ans.begin(), ans.end());
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}