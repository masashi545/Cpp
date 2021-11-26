#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

namespace BM {

int V;
const int MAX_V = 1010;
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
        if (match[v] < 0) {
            used.assign(MAX_V, false);
            if (dfs(v)) {
                res++;
            }
        }
    }
    return res;
}

} // namespace BM