#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> color(n, vector<bool>(m, false)); // false:白、true:黒
    rep(i, n) {
        rep(j, m) {
            char c;
            cin >> c;
            if (c == 'x')
                color[i][j] = true;
        }
    }

    int dp[2][1 << m];

    int *crt = dp[0];
    int *next = dp[1];
    crt[0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            for (int used = 0; used < 1 << m; ++used) {
                if ((used >> j & 1) || color[i][j]) {
                    // (i,j)にはブロックを置く必要がない
                    next[used] = crt[used & ~(1 << j)];
                } else {
                    // 2通りの向きを試す
                    int res = 0;
                    // 横向き
                    if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
                        res += crt[used | 1 << (j + 1)];
                    }
                    // 縦向き
                    if (i + 1 < n && !color[i + 1][j]) {
                        res += crt[used | 1 << j];
                    }
                    next[used] = res;
                }
            }
            swap(crt, next);
        }
    }
    cout << crt[0] << endl;
    return 0;
}

/*
in:
3 3
. . .
. x .
. . .

out:
2
*/