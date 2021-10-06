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
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d;
            int tx2 = x2[i] + d;
            if (1 <= tx1 && tx1 <= w)
                xs.push_back(tx1);
            if (1 <= tx2 && tx2 <= w)
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
    vector<int> x1(n), x2(n), y1(n), y2(n);
    rep(i, n) cin >> x1[i] >> x2[i] >> y1[i] >> y2[i];

    // 座標圧縮
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    cout << "w=" << w << endl;
    cout << "h=" << h << endl;

    // 線のある部分を塗りつぶす
    vector<vector<bool>> fld(n * 6, vector<bool>(n * 6, false));
    rep(i, n) {
        for (int y = y1[i]; y <= y2[i]; ++y) {
            for (int x = x1[i]; x <= x2[i]; ++x) {
                fld[y][x] = true;
            }
        }
    }

    const vector<int> dx = {-1, 0, 0, 1};
    const vector<int> dy = {0, -1, 1, 0};
    // 領域を数える
    int ans = 0;
    rep(y, h) {
        rep(x, w) {
            if (fld[y][x]) {
                continue;
            }
            ans++;

            // 幅優先探索
            queue<P> que;
            que.push(P(x, y));
            while (!que.empty()) {
                int sx = que.front().first;
                int sy = que.front().second;
                que.pop();

                rep(i, 4) {
                    int tx = sx + dx[i];
                    int ty = sy + dy[i];
                    if (0 <= tx && tx < w && 0 <= ty && ty < h) {
                        if (!fld[ty][tx]) {
                            que.push(P(tx, ty));
                            fld[ty][tx] = true;
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
10 10
5
1 6 4 4
1 10 8 8
4 4 1 10
9 9 1 5
10 10 6 10

out:
6
*/