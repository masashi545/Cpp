#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

namespace BM {

int V;
const int MAX_V = 2000;
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

// 二部グラフの最大マッチングを求める
int bipartite_matching() {
    int res = 0;
    match.assign(MAX_V, -1);
    rep(v, V) {
        if (match[v] < 0) { // 誰ともマッチしていないとき
            used.assign(MAX_V, false);
            if (dfs(v)) {
                res++;
            }
        }
    }
    return res;
}

} // namespace BM

// 最大安定集合を求める
// (最大安定集合)＝|V|-(最小点カバー)
// 二部グラフの場合、(最小点カバー)＝(最大マッチング)

const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, -1, 1, 0};

int main() {
    int r, c;
    cin >> r >> c;
    BM::V = r * c;

    vector<vector<char>> G(r, vector<char>(c)); // グラフ

    rep(i, r) {
        string s;
        cin >> s;
        rep(j, c) {
            G[i][j] = s[j];
        }
    }

    int num = 0; // 広告を打てるマスの個数
    rep(x, r) {
        rep(y, c) {
            if (G[x][y] == '.') {
                num++;
                rep(k, 2) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < r && 0 <= ny && ny < c) {
                        if (G[nx][ny] == '.') {
                            BM::add_edge(x * c + y, nx * c + ny);
                        }
                    }
                }
            }
        }
    }

    // 最大マッチングを求める
    int ans = BM::bipartite_matching();
    // 最大安定集合=頂点数(広告を打てるマスの個数)-最大マッチング
    cout << num - ans << endl;
    return 0;
}