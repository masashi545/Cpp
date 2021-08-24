#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 近傍探索問題
int n, m;
vector<vector<char>> G;

void dfs(int x, int y) {
    // 今いるところを.に置き換える->一度来たところは2度と探索しない
    G[x][y] = '.';

    // 近傍８方向について深さ優先探索
    for (int idx = -1; idx <= 1; idx++) {
        for (int idy = -1; idy <= 1; idy++) {
            int nx = x + idx;
            int ny = y + idy;

            if (0 <= nx && nx < n && 0 <= ny && ny < m) { // 探索範囲内であること
                if (G[nx][ny] == 'W') {                   // 遷移先が水溜りであること
                    dfs(nx, ny);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    rep(i, n) {
        vector<char> x(m);
        rep(j, m) cin >> x[j];
        G.push_back(x);
    }

    int ans = 0;
    rep(i, n) {
        rep(j, m) {
            if (G[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

/*
in:
10 12
W . . . . . . . . W W .
. W W W . . . . . W W W
. . . . W W . . . W W .
. . . . . . . . . W W .
. . . . . . . . . W . .
. . W . . . . . . W . .
. W . W . . . . . W W .
W . W . W . . . . . W .
. W . W . . . . . . W .
. . W . . . . . . . W .
out:
3
*/