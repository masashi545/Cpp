#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

/* 行列の累乗和
 * S = A + A^2 + .. + A^k
 *
 * S[k] = I + A + .. + A^(k-1)とすると、(I:単位行列)
 * (A^k ) = (A | 0)(A^(k-1)) = (A | 0)^k(I)
 * (S[k]) = (I | I)(S[k-1] ) = (I | I)  (0)
 */

typedef vector<int> vec; // ベクトルの型定義
typedef vector<vec> mat; // 行列の型定義

int M; // Mで割った余りを求める

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
    cin >> n >> k >> M;
    mat A(n * 2, vec(n * 2));
    rep(i, n) {
        rep(j, n) {
            cin >> A[i][j];
        }
        A[n + i][i] = 1;
        A[n + i][n + i] = 1;
    }

    //
    // A + .. + A^k = S[k+1] - I を求める
    //
    /*
    rep(i, n * 2) {
        rep(j, n * 2) { cout << A[i][j] << " "; }
        cout << endl;
    }*/
    A = pow(A, k + 1);
    /*
    rep(i, n * 2) {
        rep(j, n * 2) { cout << A[i][j] << " "; }
        cout << endl;
    }*/
    rep(i, n) {
        rep(j, n) {
            int s = A[n + i][j] % M;
            // Iを引く
            if (i == j) {
                s = (s - 1 + M) % M;
            }
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
in:
2 2
4
0 1
1 1

out:
1 2
2 3
*/