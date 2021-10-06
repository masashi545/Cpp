#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> dir(n); // 各牛の向き(0:F, 1:B)
    rep(i, n) {
        if (s[i] == 'B')
            dir[i] = 1;
    }

    int K = 1; // 暫定のK
    int M = n; // 暫定の最小操作回数
    for (int k = 1; k <= n; ++k) {
        vector<int> f(n); // 区間[i,i+k-1]を反転させたかどうか
        int m = 0;        // 反転操作回数
        int sumf = 0;     // f[j](j=i+k-1~i-1)の和

        // 左からｋ頭ずつ考え、その区間を右に1頭ずつずらしていく。最左の牛を前向きにするように反転させていき、全ての牛を前に向かせられるかを判定する
        bool ok = true;
        for (int i = 0; i + k <= n; ++i) {
            // 区間[i,i+k-1]に着目
            if ((dir[i] + sumf) % 2 != 0) {
                // 先頭の牛が後ろを向いているため、反転させる
                m++;
                f[i] = 1;
            }
            sumf += f[i];
            if (i - k + 1 >= 0) {
                sumf -= f[i - k + 1];
            }
        }

        // 残りの牛(n-k+1~n頭目)が前向きかを確かめる
        for (int i = n - k + 1; i <= n; ++i) {
            if ((dir[i] + sumf) % 2 != 0) {
                ok = false;
                break;
            }
            if (i - k + 1 >= 0) {
                sumf -= f[i - k + 1];
            }
        }

        // 全ての牛が前向きになっているかつ、操作回数が暫定より小さい場合、更新
        if (ok && M > m) {
            K = k;
            M = m;
        }
    }

    cout << "K = " << K << endl;
    cout << "M = " << M << endl;
    return 0;
}

/*
in:
7
BBFBFBB

out:
K = 3
M = 3
*/