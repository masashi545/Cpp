#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int m, n;
vector<vector<int>> G(15, vector<int>(15));

const vector<int> dx = {-1, 0, 0, 0, 1};
const vector<int> dy = {0, -1, 0, 1, 0};

vector<vector<int>> opt(15, vector<int>(15));  // 最適解を保存
vector<vector<int>> flip(15, vector<int>(15)); // 作業用

// (x,y)の色を返す
int get(int x, int y) {
    int c = G[x][y];
    rep(i, 5) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (0 <= xx && xx < m && 0 <= yy && yy < n) {
            c += flip[xx][yy]; // 隣接範囲で何回の反転が起こっているかを数える
        }
    }
    return c % 2;
}

// 1行目の反転の仕方を決めた場合の最小操作回数を求める
int calc(int count) {
    // 2行目からの反転の仕方を決めていく
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 上のマスが黒なら反転する
            if (get(i - 1, j) != 0) {
                flip[i][j] = 1;
                count++;
            }
        }
    }
    // 最後の行が全て白であるか確認する
    for (int j = 0; j < n; ++j) {
        if (get(m - 1, j) != 0) {
            return -1;
        }
    }

    return count;
}

int main() {
    cin >> m >> n;
    rep(i, m) {
        rep(j, n) {
            cin >> G[i][j];
        }
    }

    int ans = -1;
    // 1行目の反転の仕方を辞書順で試す
    rep(tmp, 1 << n) {
        bitset<15> bs(tmp);

        int count = 0;
        rep(i, m) {
            rep(j, n) {
                if (i == 0) {
                    if (bs.test(n - i - 1)) {
                        flip[0][i] = 1;
                        count++;
                        continue;
                    }
                }
                flip[i][j] = 0;
            }
        }

        rep(i, n) {
            if (bs.test(n - i - 1)) {
                flip[0][i] = 1;
                count++;
            }
        }

        count = calc(count);
        if (count >= 0 && (ans < 0 || count < ans)) {
            ans = count;
            rep(i, m) {
                rep(j, n) {
                    opt[i][j] = flip[i][j];
                }
            }
        }
    }

    if (ans < 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        rep(i, m) {
            rep(j, n) {
                cout << opt[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

/*
in:
4
4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1

out:
0 0 0 0 
1 0 0 1
1 0 0 1
0 0 0 0
*/