#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int r, c;
    cin >> r >> c;
    int sy, sx;
    int gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;

    vector<vector<char>> G;
    rep(i, r) {
        vector<char> x(c);
        rep(j, c) cin >> x[j];
        G.push_back(x);
    }

    vector<P> H = {P(-1, 0), P(1, 0), P(0, -1), P(0, 1)}; // 近傍4方向

    queue<P> que;
    vector<vector<int>> d(r, vector<int>(c, INF));

    que.push(P(sy, sx)); // スタート地点を入れる
    d[sy][sx] = 0;       // スタート地点までは距離0

    while (!que.empty()) {
        P p = que.front(); // ある地点ｐについて考える
        que.pop();

        // 地点ｐがゴールであれば終了
        if (p.first == gy && p.second == gx) {
            break;
        }
        // 近傍4方向について幅優先探索
        for (int i = 0; i < 4; i++) {
            int ny = p.first + H[i].first;
            int nx = p.second + H[i].second;

            if (0 <= ny && ny < r && 0 <= nx && nx < c) { // 探索範囲内であること
                if (G[ny][nx] == '.') {                   // 通路であること
                    if (d[ny][nx] == INF) {               // まだ訪れたことがないこと
                        que.push(P(ny, nx));
                        d[ny][nx] = d[p.first][p.second] + 1;
                    }
                }
            }
        }
    }
    /*
    rep(i, r) {
        rep(j, c) {
            if (d[i][j] == INF)
                cout << "# ";
            else
                cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    cout << d[gy][gx] << endl;
    return 0;
}