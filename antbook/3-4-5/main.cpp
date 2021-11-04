#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

/* 一般のm項間漸化式の計算
 * a[n+m]=m-1~0Σ b[i]*a[n+i]
 *
 * ( a[n+m] ) = (b[m-1] ... b[1] b[0]  c)(a[n+m-1])
 * (a[n+m-1]) = (  1    ...  0    0    0)(a[n+m-2])
 * (   :    ) = (  :    ...  :    :    :)(   :    )
 * ( a[n+1] ) = (  0    ...  1    0    0)(  a[n]  )
 * (   1    ) = (  0    ...  0    0    1)(   1    )
 */

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
    int n;
    cin >> n;

    /* 左からi個までを、
     * a[i]...赤・緑ともに偶数個
     * b[i]...赤・緑の片方が奇数個
     * c[i]...赤・緑ともに奇数個
     * になるように塗る総数
     */

    /* a[i+1] = 2 * a[i] + b[i]
     * b[i+1] = 2 * a[i] + 2 * b[i] + 2 * c[i]
     * c[i+1] = b[i] + 2 * c[i]
     */

    mat A(3, vec(3));
    A[0] = {2, 1, 0};
    A[1] = {2, 2, 2};
    A[2] = {0, 1, 2};
    A = pow(A, n);
    cout << A[0][0] << endl;

    return 0;
}

/*
in:
1

out:
2

in:
2

out:
6
*/