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
bool comp_edge(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

struct point {
    int idx;
    int x, y;
};
bool comp_point_x(const point &p1, const point &p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    } else {
        return p1.x < p2.x;
    }
}
bool comp_point_y(const point &p1, const point &p2) {
    if (p1.y == p2.y) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

int main() {
    int n;
    cin >> n;
    vector<point> G(n);
    rep(i, n) {
        G[i].idx = i;
        cin >> G[i].x >> G[i].y;
    }

    // 最小全域木に採用されうる辺は、xまたはyについて隣同士である頂点間の辺に限られる
    vector<edge> es;
    sort(G.begin(), G.end(), comp_point_x);
    rep(i, n - 1) {
        edge e;
        e.u = G[i].idx;
        e.v = G[i + 1].idx;
        e.cost = abs(G[i].x - G[i + 1].x);
        es.push_back(e);
    }
    sort(G.begin(), G.end(), comp_point_y);
    rep(i, n - 1) {
        edge e;
        e.u = G[i].idx;
        e.v = G[i + 1].idx;
        e.cost = abs(G[i].y - G[i + 1].y);
        es.push_back(e);
    }

    union_find uf;
    uf.init(n);
    sort(es.begin(), es.end(), comp_edge);
    int ans = 0;
    rep(i, int(es.size())) {
        edge e = es[i];
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            ans += e.cost;
        }
    }

    cout << ans << endl;
    return 0;
}
