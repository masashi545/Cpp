#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int n;

// x1, x2について座標圧縮し、圧縮した際の幅を返す
int compress(vector<int> &x1, vector<int> &x2, int w) {
    vector<int> xs;

    rep(i, n) {
        for (int d = 0; d <= 1; ++d) {
            int tx1 = x1[i] - d;
            int tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 < w)
                xs.push_back(tx1);
            if (0 <= tx2 && tx2 < w)
                xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end()); // std::unique関数によって、xsの(隣接する)重複部分が削除され、erase関数によって、末尾に残ったゴミを削除する

    rep(i, n) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

int main() {
    int w, h;
    cin >> w >> h >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    rep(i, n) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x2[i]--;
        y2[i]--;
    }

    // 座標圧縮
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    // cout << "w=" << w << endl;
    // cout << "h=" << h << endl;

    // テープを貼ったところは、あらかじめ塗ったことにしておく
    vector<vector<short>> G(w, vector<short>(h, 0));
    // 2次imos法->端に＋1、-1のマークをつけ、累積和を計算していく
    rep(i, n) {
        for (int y = y1[i]; y <= y2[i]; ++y) {
            G[x1[i]][y]++;
        }
        for (int y = y1[i]; y <= y2[i]; ++y) {
            if (x2[i] + 1 < w)
                G[x2[i] + 1][y]--;
        }
    }
    rep(y, h) {
        rep(x, w - 1) {
            G[x + 1][y] += G[x][y];
        }
    }
    /*
    rep(i, h) {
        rep(j, w) {
            if (G[j][h - i - 1] > 0) {
                cout << "# ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }*/

    const vector<int>
        dx = {-1, 0, 0, 1};
    const vector<int> dy = {0, -1, 1, 0};

    int ans = 0;
    rep(i, w) {
        rep(j, h) {
            if (G[i][j] == 0) {
                ans++;
                queue<P> que; // 探索地点を管理

                que.push(P(i, j)); // スタート地点を入れる
                G[i][j]++;

                while (!que.empty()) {
                    P p = que.front(); // ある地点ｐについて考える
                    que.pop();

                    // 近傍4方向について深さ優先探索
                    rep(i, 4) {
                        int nx = p.first + dx[i];
                        int ny = p.second + dy[i];

                        if (0 <= nx && nx < w && 0 <= ny && ny < h) { // 探索範囲内であること
                            if (G[nx][ny] == 0) {                     // まだ塗られていない場所であること
                                que.push(P(nx, ny));
                                G[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

/*
in:
17 8
10
1 6 5 8
2 1 4 7
1 0 5 1
6 1 7 7
7 7 9 8
7 0 9 2
9 1 10 7
11 0 16 1
12 1 15 7
11 7 16 8
*/