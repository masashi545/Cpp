#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

vector<P> H = {P(-1, 0), P(1, 0), P(0, -1), P(0, 1)}; // 近傍4方向

void dfs(int x, int y, vector<vector<int>> &G) {
    // 今いるところを0に変えていく
    G[x][y] = 0;

    // 近傍4方向について深さ優先探索
    rep(i, 4) {
        int nx = x + H[i].first;
        int ny = y + H[i].second;

        if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) { // 探索範囲内であること
            if (G[nx][ny] == 1) {                     // 遷移先が陸地であること
                dfs(nx, ny, G);
            }
        }
    }
}

bool dfs1(int x, int y, vector<vector<int>> &G) {
    // 今いるところを1に変えていく
    G[x][y] = 1;
    if (x == 0 || x == 3 || y == 0 || y == 3) {
        return true;
    }

    // 近傍4方向について深さ優先探索
    rep(i, 4) {
        int nx = x + H[i].first;
        int ny = y + H[i].second;

        if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) { // 探索範囲内であること
            if (G[nx][ny] == 0 && dfs1(nx, ny, G)) {  // 遷移先が0であること
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> a(16);
    rep(i, 16) cin >> a[i];

    int ans = 0;
    rep(tmp, 1 << 16) {
        bitset<16> bs(tmp);

        // 全ての村を含んでいるか
        bool cover = true;
        rep(i, 16) {
            if (a[i] && !bs.test(i)) {
                cover = false;
                break;
            }
        }
        if (!cover)
            continue;

        // 自己交差がないか
        bool closs = true;
        vector<vector<int>> G(4, vector<int>(4));
        rep(i, 4) {
            rep(j, 4) {
                G[i][j] = bs[i * 4 + j];
            }
        }

        bool b = false;
        rep(i, 4) {
            rep(j, 4) {
                if (G[i][j] == 1) {
                    dfs(i, j, G); // 連結している1を0に置き換える
                    b = true;
                    break;
                }
            }
            if (b)
                break;
        }

        rep(i, 4) {
            rep(j, 4) {
                if (G[i][j] == 1)
                    closs = false;
            }
        }

        if (!closs) {
            rep(i, 4) {
                rep(j, 4) {
                    cout << bs[i * 4 + j] << " ";
                }
                cout << endl;
            }
            cout << "No" << endl;
            continue;
        }

        // 0が孤立していないか
        bool zero = true;
        rep(i, 4) {
            rep(j, 4) {
                G[i][j] = bs[i * 4 + j];
            }
        }
        rep(i, 2) {
            rep(j, 2) {
                if (G[i + 1][j + 1] == 0)
                    zero = dfs1(i + 1, j + 1, G);
                if (!zero)
                    break;
            }
            if (!zero)
                break;
        }

        if (zero) {
            ans++;
            cout << "Yes" << endl;
        } else {
            rep(i, 4) {
                rep(j, 4) {
                    cout << bs[i * 4 + j] << " ";
                }
                cout << endl;
            }
            cout << "No" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}