#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct edge {
    int to;
    int cost;
};

int n, m;
const int N_MAX = 10000;
vector<vector<edge>> G(N_MAX);

int prim() {
    vector<bool> used(n, false);                  // 取り込んだかどうか
    priority_queue<P, vector<P>, greater<P>> que; // 考慮する辺集合を入れる first:cost, second:to
    que.push(P(0, 0));
    int ans = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;

        if (used[v])
            continue;

        ans += p.first;
        used[v] = true;

        rep(i, int(G[v].size())) {
            edge e = G[v][i];
            if (!used[e.to]) {
                que.push(P(e.cost, e.to));
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back(edge{y, w});
        G[y].push_back(edge{x, w});
    }

    cout << prim() << endl;
    return 0;
}
