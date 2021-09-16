#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct union_find {
    vector<int> par;   // 親
    vector<int> depth; // 木の深さ

    // n要素で初期化
    void init(int n) {
        rep(i, n) {
            par.push_back(i);
            depth.push_back(0);
        }
    }

    // 木の根を求める
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = find(par[x]);
            return par[x];
        }
    }

    // ｘとｙの属する集合を併合
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) { // 同じ値だったら、既に同じ集合なので併合する必要はない
            return;
        }

        if (depth[x] < depth[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (depth[x] == depth[y]) {
                depth[x]++;
            }
        }
    }

    // ｘとｙが同じ集合に属するか否か
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

struct edge {
    int u, v;
    int cost;
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

int n, m;
const int M_MAX = 10000;
vector<edge> es(M_MAX);

int kruskal() {
    union_find uf;
    sort(es.begin(), es.begin() + m, comp);
    uf.init(n);
    int ans = 0;
    rep(i, m) {
        edge e = es[i];
        if (!uf.same(e.u, e.v)) { // 負の枝も存在する場合、"|| e.cost < 0" を付け加える
            uf.unite(e.u, e.v);
            ans += e.cost;
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        es[i] = edge{x - 1, y - 1, w};
    }

    cout << kruskal() << endl;
    return 0;
}
