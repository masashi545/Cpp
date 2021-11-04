#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

/* A[n+k] = 1~kΣ C[i] * A[n+k-i]
 * a[n+m]= 0~m-1Σ b[i]*a[n+i]
 *
 * ( A[n+k] ) = (C[1] C[2] ... C[k-1] C[k])(A[n+k-1])
 * (A[n+k-1]) = ( 1    0   ...  0      0  )(A[n+k-2])
 * (   :    ) = ( :   ...  ...  :      :  )(   :    )
 * ( A[n+2] ) = ( 0    0   ...  0      0  )( A[n+1] )
 * ( A[n+1] ) = ( 0    0   ...  1      0  )(  A[n]  )
 */

typedef bitset<32> bs;
typedef vector<bs> vec;  // ベクトルの型定義
typedef vector<vec> mat; // 行列の型定義

// A * Bを計算する
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size())); // (Aの縦)ｘ(Bの横)の大きさの行列ができる
    rep(i, A.size()) {
        rep(k, B.size()) {
            rep(j, B[0].size()) {
                C[i][j] = (C[i][j] ^ (A[i][k] & B[k][j]));
            }
        }
    }
    return C;
}

// A^nを計算する
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size())); // (Aの縦)x(Aの縦)の大きさの正方行列ができる
    rep(i, A.size()) {
        B[i][i] = bs(UINT_MAX); // 対角成分はすべて1
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
    int k, m;
    cin >> k >> m;
    vec A(k), C(k);
    rep(i, k) {
        ll x;
        cin >> x;
        A[i] = bs(x);
    }
    rep(i, k) {
        ll x;
        cin >> x;
        C[i] = bs(x);
    }

    if (m <= k) {
        cout << A[m - 1].to_ullong() << endl;
        return 0;
    }

    mat B(k, vec(k));
    B[0] = C;
    rep(i, k - 1) {
        B[i + 1][i] = bs(UINT_MAX);
    }

    B = pow(B, m - k);
    /*
    rep(i, k) {
        rep(j, k) {
            cout << B[i][j] << " "; // bitsetを整数に直して出力
        }
        cout << endl;
    }*/

    mat D(k, vec(1));
    rep(i, k) {
        D[i][0] = A[k - i - 1];
    }
    D = mul(B, D);

    cout << D[0][0].to_ullong() << endl; // bitsetを整数に直して出力
    return 0;
}