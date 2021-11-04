#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

vector<int> L;

int const ST_SIZE = (1 << 15) - 1;
vector<double> vx(ST_SIZE), vy(ST_SIZE); // 各節点の値(ベクトル)
vector<double> ang(ST_SIZE);             // 各節点の角度

// ノードを初期化(垂直に並んでいる)
void init(int k, int l, int r) {
    ang[k] = 0.0;
    vx[k] = 0.0;

    if (r - l == 1) { // 葉
        vy[k] = L[l];
    } else { // 葉以外
        int chl = 2 * k + 1;
        int chr = 2 * k + 2;
        init(chl, l, (l + r) / 2);
        init(chr, (l + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];
    }
}

// 場所kの角度をaだけ変更する
// vのノードのidx
void change(int k, double a, int v, int l, int r) {
    if (l < k && k < r) {
        int chl = 2 * v + 1;
        int chr = 2 * v + 2;
        int m = (l + r) / 2;
        change(k, a, chl, l, m);
        change(k, a, chr, m, r);
        if (k <= m) {
            ang[v] += a;
        }

        vx[v] = vx[chl] + (cos(ang[v]) * vx[chr] - sin(ang[v]) * vy[chr]);
        vy[v] = vy[chl] + (sin(ang[v]) * vx[chr] + cos(ang[v]) * vy[chr]);
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    L.resize(n);
    rep(i, n) cin >> L[i];
    vector<int> S(c), A(c);
    rep(i, c) cin >> S[i] >> A[i];

    vector<double> prv(n, M_PI); // 角度の変化を調べるため、現在の角度を保持。初期状態180度

    init(0, 0, n); // セグ木の初期化

    cout << fixed << setprecision(2);
    rep(i, c) {
        int s = S[i];
        double a = A[i] / 360.0 * 2 * M_PI; // ラジアンに直す

        change(s, a - prv[s], 0, 0, n);
        prv[s] = a;

        cout << vx[0] << " " << vy[0] << endl;
    }
    return 0;
}

/*
in:
2 1
10 5
1 90

out:
5.00 10.00

in:
3 2
5 5 5
1 270
2 90

out:
-10.00 5.00
-5.00 10.00
*/