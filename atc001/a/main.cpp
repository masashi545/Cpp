#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> G;
    rep(i, h) {
        vector<char> x(w);
        rep(j, w) cin >> x[j];
        G.push_back(x);
    }

    vector<P> H = {P(-1, 0), P(1, 0), P(0, -1), P(0, 1)}; // 近傍4方向

    int sx, sy; // スタート地点の座標
    int gx, gy; // ゴール地点の座標

    // スタート地点とゴール地点を探索
    rep(i, h) {
        rep(j, w) {
            if (G[i][j] == 's') {
                sx = i;
                sy = j;
            }
            if (G[i][j] == 'g') {
                gx = i;
                gy = j;
            }
        }
    }

    stack<P> stk;                                            // 探索地点を管理
    vector<vector<bool>> reached(h, vector<bool>(w, false)); // 既に訪れたか

    stk.push(P(sx, sy)); // スタート地点を入れる
    reached[sx][sy] = true;

    while (!stk.empty()) {
        P p = stk.top(); // ある地点ｐについて考える
        stk.pop();

        // 地点ｐがゴールであれば終了
        if (p.first == gx && p.second == gy) {
            cout << "Yes" << endl;
            return 0;
        }
        // 近傍4方向について幅優先探索
        rep(i, 4) {
            int nx = p.first + H[i].first;
            int ny = p.second + H[i].second;

            if (0 <= nx && nx < h && 0 <= ny && ny < w) { // 探索範囲内であること
                if (G[nx][ny] != '#') {                   // 通路であること
                    if (!reached[nx][ny]) {               // まだ訪れたことがないこと
                        stk.push(P(nx, ny));
                        reached[nx][ny] = true;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}