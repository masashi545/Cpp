#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<P> H = {P(-1, 0), P(1, 0), P(0, -1), P(0, 1)}; // 近傍4方向

void dfs(int x, int y, vector<vector<char>> &G) {
    // 今いるところを海に変えていく
    G[x][y] = 'x';

    // 近傍4方向について深さ優先探索
    rep(i, 4) {
        int nx = x + H[i].first;
        int ny = y + H[i].second;

        if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) { // 探索範囲内であること
            if (G[nx][ny] == 'o') {                     // 遷移先が陸地であること
                dfs(nx, ny, G);
            }
        }
    }
}

// 全ての陸地が連結しているか否か
bool connect(int x, int y, vector<vector<char>> G) {
    dfs(x, y, G); // 連結している陸地を海に置き換える
    // すべてが海になっていればOK
    rep(i, 10) {
        rep(j, 10) {
            if (G[i][j] == 'o')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> G;
    rep(i, 10) {
        vector<char> x(10);
        rep(j, 10) cin >> x[j];
        G.push_back(x);
    }

    rep(i, 10) {
        rep(j, 10) {
            if (connect(i, j, G)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}