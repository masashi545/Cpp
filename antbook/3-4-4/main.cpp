#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

// フィボナッチ数列
/*
 * F[0]=0
 * F[1]=1
 * F[n+2]=F[n+1]+F[n]
 *
 * (F[n+2]) = (1 1)(F[n+1])
 * (F[n+1]) = (1 0)( F[n] )
 *
 * (F[n+1]) = A^n(F[1]) = A^n(1)
 * ( F[n] ) =    (F[0]) =    (0)
 *
 * A^nを繰り返し二乗法で求める->O(logn)
 */

typedef vector<int> vec; // ベクトルの型定義
typedef vector<vec> mat; // 行列の型定義

const int M = 10000; // Mで割った余りを求める

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
    ll n;
    cin >> n;

    mat A(2, vec(2));
    A[0] = {1, 1};
    A[1] = {1, 0};
    A = pow(A, n); // A^n

    cout << A[1][0] << endl; // Aの左下[1][0]が、F[n]
    return 0;
}

/*
in:
10

out:
55
*/