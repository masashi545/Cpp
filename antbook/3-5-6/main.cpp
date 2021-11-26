#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
using grid = vector<vector<int>>;
const int INF = 1e9 + 7;

namespace BM {

int V;
const int MAX_V = 7000;
vector<vector<int>> G(MAX_V); // グラフの隣接リスト
vector<int> match(MAX_V);     // マッチングのペア
vector<bool> used(MAX_V);     // DFSで既に調べたかのフラグ

// uとvを結ぶ辺をグラフに追加する
void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

// 増加パスをDFSで探す
bool dfs(int v) {
    used[v] = true;
    rep(i, G[v].size()) {
        int u = G[v][i];
        int w = match[u];                    // 頂点uとマッチしている頂点
        if (w < 0 || (!used[w] && dfs(w))) { // 誰ともマッチしていない、または、増加パスが新たに見つかる
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

// 二部グラフの最大マッチングを求める（マッチング数がpになったら、終了するようアレンジ）
int bipartite_matching_arrange(int p) {
    int res = 0;
    match.assign(MAX_V, -1);
    rep(v, V) { // v..考慮するドア
        used.assign(MAX_V, false);
        if (dfs(v)) {
            res++;
            if (res == p) {
                return v; // どこまで考慮してマッチング数がpになったかを返す
            }
        }
    }
    return -1; // 全て考慮しても、マッチング数がpにならなかった
}

} // namespace BM

// 4方向への動き方
const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, -1, 1, 0};

const int MAX_X = 12, MAX_Y = 12;
int X, Y;
vector<vector<char>> G(MAX_X, vector<char>(MAX_Y));

vector<P> door;                                                                             // ドアの座標
vector<P> person;                                                                           // 人の　座標
vector<vector<grid>> dist(MAX_X, vector<grid>(MAX_Y, grid(MAX_X, vector<int>(MAX_Y, -1)))); // dist[x][y]..(x,y)にあるドアから、各マスへの最短距離

// 幅優先探索で、(x,y)にあるドアから、各マスへの最短距離を求める
void bfs(int x, int y, vector<vector<int>> &d) {
    queue<P> que; // 探索地点を管理

    que.push(P(x, y)); // スタート地点を入れる
    d[x][y] = 0;       // スタート地点までは距離0

    while (!que.empty()) {
        P p = que.front(); // ある地点ｐについて考える
        que.pop();

        // 近傍4方向について幅優先探索
        rep(i, 4) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (0 <= nx && nx < X && 0 <= ny && ny < Y) { // 探索範囲内であること
                if (G[nx][ny] == '.') {                   // 通路であること
                    if (d[nx][ny] < 0) {                  // まだ訪れたことがないこと
                        que.push(P(nx, ny));
                        d[nx][ny] = d[p.first][p.second] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> X >> Y;
    int n = X * Y; // 端から端までの距離（最大距離）

    rep(x, X) {
        rep(y, Y) {
            cin >> G[x][y];
        }
    }

    // 各ドアからの最短距離を求める
    rep(x, X) {
        rep(y, Y) {
            if (G[x][y] == 'D') {
                door.push_back(P(x, y));
                bfs(x, y, dist[x][y]);
            } else if (G[x][y] == '.') {
                person.push_back(P(x, y));
            }
        }
    }

    // (時刻t,ドアd)のペアと、人pの二部グラフを考え、最大マッチングを求める
    // グラフを作成
    int D = door.size();
    int Ps = person.size();
    /*
     * 0~D-1..時刻1に対応するドア
     * D~2D-1..時刻2に対応するドア
     * ...
     * (t-1)D~tD-1..時刻tに対応するドア
     * ...
     * (n-1)D~nD-1..時刻nに対応するドア
     *
     * nD~nD+Ps-1..人
     */
    rep(d, D) {
        rep(p, Ps) {
            // 人pが、ドアdへ辿り着く最短距離(時間)
            int T = dist[door[d].first][door[d].second][person[p].first][person[p].second];
            if (T >= 0) {                      // 辿り着けるなら
                for (int t = T; t <= n; t++) { // 時刻T以降のドアdには、人pが辿り着けるので、枝を追加
                    BM::add_edge((t - 1) * D + d, n * D + p);
                }
            }
        }
    }

    // 全員が脱出するための最小時間を計算する
    BM::V = n * D;

    if (Ps == 0) {
        cout << 0 << endl;
        return 0;
    }

    // BM::bipartite_matchingをアレンジ
    int ans = BM::bipartite_matching_arrange(Ps);
    // cout << "ans : " << ans << endl;
    /* 隣接リストを出力
    rep(i, n * D + Ps) {
        cout << i << " : ";
        rep(j, BM::G[i].size()) {
            cout << BM::G[i][j] << " ";
        }
        cout << endl;
    }
    */
    if (ans > 0) {
        cout << ans / D + 1 << endl; // 時刻を求めたいので、(考慮したドア)/(ドア数)＋1
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}

/*
in:
5 5
X X D X X
X . . . X
D . . . X
X . . . D
X X X X X

out:
3

in:
5 12
X X X X X X X X X X X X
X . . . . . . . . . . D
X . X X X X X X X X X X
X . . . . . . . . . . X
X X X X X X X X X X X X

out:
21

in:
5 5
X D X X X
X . X . D
X X . X X
D . X . X
X X X D X

out:
impossible
*/