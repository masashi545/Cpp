#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct edge {
    int to;   // 行き先
    int cap;  // 容量
    int cost; // コスト
    int rev;  // 逆辺
};

int V; // 頂点数
const int MAX_V = 110;
vector<vector<edge>> G(MAX_V);          // 隣接リスト(ｓ=0,t=V-1)
vector<int> h(MAX_V);                   // ポテンシャル(ダイクストラが使えるようにに負の辺をなくすため)
vector<int> dist(MAX_V);                // sから各頂点への最短コスト
vector<int> prevv(MAX_V), preve(MAX_V); // 直前の頂点と辺

// fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(edge{to, cap, cost, (int)G[to].size()});
    G[to].push_back(edge{from, 0, -cost, (int)G[from].size() - 1}); // 逆辺はコストを負にする
}

// sからtへの流量fの最小費用流を求める
// 流せない場合は-1を返す
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
        // ベルマンフォード法により、s-t間の最短路を求める
        /*
            dist.assign(V, INF);
            dist[s] = 0;
            bool update = true;
            while (update) {
                update = false;
                rep(v, V) {
                    if (dist[v] == INF) {
                        continue;
                    }
                    rep(i, G[v].size()) {
                        edge &e = G[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            } // dist[t]に最短路が求まった
            */
        // ダイクストラ法により、s-t間の最短路を求める
        h.assign(V, 0);
        priority_queue<P, vector<P>, greater<P>> que; // first: 最短距離、second: 頂点番号
        dist.assign(V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) {
                continue;
            }
            rep(i, G[v].size()) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        } // dist[t]に最短路が求まった

        if (dist[t] == INF) {
            // これ以上流せない
            return -1;
        }

        // ポテンシャルの更新
        rep(v, V) h[v] += dist[v];

        // s-t間の最短路に沿ってできるだけ(容量一杯)流す
        int d = f;
        for (int v = t; v != s; v = prevv[v]) { // 最短路を逆向きにたどり、最小の容量の辺を探す
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;             // 流す
        res += d * dist[t]; // 流した量×コストを加算する

        for (int v = t; v != s; v = prevv[v]) { // 最短路を逆向きにたどり、残余ネットワークを構築
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}

int main() {
    int E, F;
    cin >> V >> E >> F;
    rep(i, E) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add_edge(a, b, c, d);
    }

    cout << min_cost_flow(0, V - 1, F) << endl;
    return 0;
}

/*
in:
5 7 9
0 1 10 2
0 2 2 4
1 2 6 6
1 3 6 2
2 4 5 2
3 2 3 3
3 4 8 6

out:
80
*/