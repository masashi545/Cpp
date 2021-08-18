#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int h, w;
vector<vector<char>> G;
bool ans = false;

bool dfs(int x, int y) {
    if (x < 0 || h <= x || y < 0 || w <= y) { // 探索範囲外なら打ち止め
        return false;
    }
    if (G[x][y] == '#') { // 現在位置が壁なら打ち止め
        return false;
    }

    if (G[x][y] == 'g') { // 現在位置がゴールならOK
        return true;
    }

    // 現在位置を壁に変更。一度探索した場所は2度と探索しないように。
    G[x][y] = '#';

    // 近傍4方向について深さ優先探索
    if (dfs(x - 1, y))
        return true;
    if (dfs(x + 1, y))
        return true;
    if (dfs(x, y - 1))
        return true;
    if (dfs(x, y + 1))
        return true;

    return false;
}

int main() {
    cin >> h >> w;

    rep(i, h) {
        vector<char> x(w);
        rep(j, w) cin >> x[j];
        G.push_back(x);
    }

    int sx, sy; // スタート地点の座標
    rep(i, h) {
        rep(j, w) {
            if (G[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }
    }

    cout << (dfs(sx, sy) ? "Yes" : "No") << endl;
    return 0;
}