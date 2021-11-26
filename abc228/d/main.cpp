#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct union_find {
    // Union-Find木の実装
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

        // union_findではないが、、常に根をyに合わせる
        par[x] = y;
    }

    // ｘとｙが同じ集合に属するか否か
    bool same(int x, int y) {
        return find(x) == find(y);
    }
}; // struct union_find

const int N = pow(2, 20);
vector<ll> A(N, -1);

int main() {
    union_find uf;
    uf.init(N);

    vector<int> next(N);
    rep(i, N) next[i] = i;

    int q;
    cin >> q;
    rep(i, q) {
        int t;
        ll x;
        cin >> t >> x;
        if (t == 1) {
            int h = x % N;
            h = uf.find(h);
            A[h] = x;
            uf.unite(h, (h + 1) % N); // 根を、右の集合の根にする
        } else {                      // t == 2
            cout << A[x % N] << endl;
        }
    }

    return 0;
}