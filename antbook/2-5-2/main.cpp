#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<vector<P>> G(n);
    rep(i, r) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x - 1].push_back(P(y - 1, w));
        G[y - 1].push_back(P(x - 1, w));
    }

    vector<int> dist1(n, INF);                    // 1番目の最短距離
    vector<int> dist2(n, INF);                    // 2番目の最短距離
    priority_queue<P, vector<P>, greater<P>> que; // 最短距離が確定した頂点に隣接している頂点（first:暫定の最短距離、 second:頂点）
    dist1[0] = 0;
    que.push(P(0, 0));
    while (!que.empty()) {
        // まだ使われていない頂点のうち、距離が最小のものを探す
        P p = que.top();
        que.pop();
        int d = p.first;
        int v = p.second; // vについては最短距離確定

        if (dist2[v] < d)
            continue;

        // vと隣接している頂点について、最短距離を更新
        rep(i, int(G[v].size())) {
            P e = G[v][i];
            int d2 = d + e.second;
            if (d2 < dist1[e.first]) {
                swap(dist1[e.first], d2);
                que.push(P(dist1[e.first], e.first));
            }
            if (dist1[e.first] < d2 && d2 < dist2[e.first]) {
                dist2[e.first] = d2;
                que.push(P(dist2[e.first], e.first));
            }
        }
    }

    cout << dist2[n - 1] << endl;
    return 0;
}

/*
in:
4 4
1 2 100
2 3 250
2 4 200
3 4 100

out:
450
*/