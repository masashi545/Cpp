#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    double lb = 0;
    double ub = INF;
    rep(i, 100) {
        double mid = (lb + ub) / 2;
        vector<double> y(n);
        rep(i, n) y[i] = v[i] - mid * w[i];
        sort(y.begin(), y.end());
        // yの大きい方からk個選んで和が0以上だったらtrue
        double sum = 0;
        rep(i, k) {
            sum += y[n - i - 1];
        }
        if (sum >= 0) {
            lb = mid;
        } else {
            ub = mid;
        }
        cout << "lb=" << lb << ", ub=" << ub << endl;
    }

    cout << ub << endl;
    return 0;
}

/*
in:
3 
2
2 2
5 3
2 1

out:
0.75
*/