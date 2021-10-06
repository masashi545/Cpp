#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

// 初期の高さｈ、ｔ秒後の高さを求める
double height(int h, int t) {
    if (t < 0)
        return h;
    double T = sqrt(h / 5.0); // 床に着くまでの時間
    int k = t / T;
    if (k % 2 == 0) { // 偶数
        return h - 5 * (t - k * T) * (t - k * T);
    } else { // 奇数
        return h - 5 * ((k + 1) * T - t) * ((k + 1) * T - t);
    }
}

int main() {
    int n, h, r, t;
    cin >> n >> h >> r >> t;

    vector<double> y(n);
    rep(i, n) {
        y[i] = height(h, t - i);
    }
    sort(y.begin(), y.end());
    rep(i, n) {
        cout << fixed << setprecision(2) << y[i] + 2 * r * i / 100.0 << " ";
    }
    cout << endl;
    return 0;
}

/*
in:
1
10
10
100

out:
4.95

in:
2
10
10
100

out:
4.95
10.20
*/
