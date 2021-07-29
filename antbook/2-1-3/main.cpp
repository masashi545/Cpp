#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

// 迷路の最短路

int n, m;
vector<vector<char>> G;

vector<P> H = {P(-1, 0), P(1, 0), P(0, -1), P(0, 1)}; // 近傍4方向

int sx, sy; // スタート地点の座標
int gx, gy; // ゴール地点の座標

int bfs(vector<vector<int>> &d) {

    queue<P> que; // 探索地点を管理

    que.push(P(sx, sy)); // スタート地点を入れる
    d[sx][sy] = 0;       // スタート地点までは距離0

    while (!que.empty()) {
        P p = que.front(); // ある地点ｐについて考える
        que.pop();

        // 地点ｐがゴールであれば終了
        if (p.first == gx && p.second == gy) {
            break;
        }
        // 近傍4方向について幅優先探索
        for (int i = 0; i < 4; i++) {
            int nx = p.first + H[i].first;
            int ny = p.second + H[i].second;

            if (0 <= nx && nx < n && 0 <= ny && ny < m) { // 探索範囲内であること
                if (G[nx][ny] != '#') {                   // 通路であること
                    if (d[nx][ny] == INF) {               // まだ訪れたことがないこと
                        que.push(P(nx, ny));
                        d[nx][ny] = d[p.first][p.second] + 1;
                    }
                }
            }
        }
    }
    return d[gx][gy];
}

int main() {
    cin >> n >> m;
    rep(i, n) {
        vector<char> x(m);
        rep(j, m) cin >> x[j];
        G.push_back(x);
    }

    vector<vector<int>> d(n, vector<int>(m, INF)); // 各地点までの最短距離を格納。INFで初期化

    // スタート地点とゴール地点を探索
    rep(i, n) {
        rep(j, m) {
            if (G[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (G[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }

    int ans = bfs(d);
    cout << ans << endl;
    return 0;
}

/*
10 10
# S # # # # # # . #
. . . . . . # . . #
. # . # # . # # . #
. # . . . . . . . .
# # . # # . # # # #
. . . . # . . . . #
. # # # # # # # . #
. . . . # . . . . .
. # # # # . # # # .
. . . . # . . . G #
*/