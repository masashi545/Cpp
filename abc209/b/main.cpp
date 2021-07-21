#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    rep(i, n) {
        int a;
        cin >> a;
        sum += a;
        if (i % 2 == 1) {
            sum--;
        }
    }
    if (sum <= x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}