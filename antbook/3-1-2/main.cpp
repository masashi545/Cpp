#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> l(n);
    rep(i, n) cin >> l[i];

    double lb = 0;
    double ub = INF;

    rep(i, 100) { // 小数値の収束判定は繰り返し回数を指定するか、EPSで抑える。後者の場合、浮動小数点数の精度に注意。
        double mid = (lb + ub) / 2;
        int num = 0;
        rep(i, n) {
            num += int(l[i] / mid);
        }
        if (num >= k) {
            lb = mid;
        } else {
            ub = mid;
        }
        // cout << "lb=" << lb << ", ub=" << ub << endl;
    }

    cout << fixed << setprecision(2) << floor(ub * 100) / 100 << endl;
    return 0;
}

/*
in:
4
11
8.02
7.43
4.57
5.39

out:
2.00
*/