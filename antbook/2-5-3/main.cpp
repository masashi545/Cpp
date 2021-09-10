#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

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

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<edge> es(r);
    rep(i, r) {
        int x, y, d;
        cin >> x >> y >> d;
        es[i] = edge{x, n + y, -d};
    }

    union_find uf;
    sort(es.begin(), es.end(), comp);
    uf.init(n + m);
    ll ans = 10000 * (n + m);
    rep(i, r) {
        edge e = es[i];
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            ans += e.cost;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
in:
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781

out:
71071
*/