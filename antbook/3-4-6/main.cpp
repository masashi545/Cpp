#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

typedef vector<int> vec; // ベクトルの型定義
typedef vector<vec> mat; // 行列の型定義

const int M = 10007; // Mで割った余りを求める

// A*Bを計算する
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size())); // (Aの縦)ｘ(Bの横)の大きさの行列ができる
    rep(i, A.size()) {
        rep(k, B.size()) {
            rep(j, B[0].size()) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
            }
        }
    }
    return C;
}

// A^nを計算する
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size())); // (Aの縦)x(Aの縦)の大きさの正方行列ができる
    rep(i, A.size()) {
        B[i][i] = 1; // 対角成分はすべて1
    }

    // 繰り返し二乗法
    while (n > 0) {
        if (n & 1) { // 2進数で1のビットのとき、繰り返し2乗されてきたAを掛け合わせる
            B = mul(B, A);
        }
        A = mul(A, A); // Aを2乗していく
        n >>= 1;
    }
    return B;
}

int main() {
    int n, k;
    cin >> n >> k;
    mat A(n, vec(n));
    rep(i, n) {
        rep(j, n) {
            cin >> A[i][j];
        }
    }

    /* G(k)[u][v]...uからvへの長さkのパスの総数
     * G(1)=グラフの隣接行列
     *
     * u -> w の長さk1のパス
     * w -> v の長さk2のパスを合わせて、k1+k2のパスができる
     * G(k1+k2)[u][v] = n~1Σ G(k1)[u][w] * G(k2)[w][v]
     * つまり、
     * G(k1+k2) = G(k1)G(k2)
     * よって、
     * G(k) = G(1)^k
     */

    A = pow(A, k);
    int sum = 0;
    rep(i, n) {
        rep(j, n) {
            sum = (sum + A[i][j]) % M;
        }
    }
    cout << sum << endl;

    return 0;
}

/*
in:
4 2
0 1 1 0
0 0 1 0
0 0 0 1
1 0 0 0

out:
6
*/