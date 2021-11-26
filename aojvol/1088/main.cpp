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
const int MAX_V = 5000;
vector<vector<edge>> G(MAX_V);          // 隣接リスト(ｓ=0,t=V-1)
vector<int> h(MAX_V);                   // ポテンシャル(ダイクストラが使えるようにに負の辺をなくすため)
vector<int> dist(MAX_V);                // sから各頂点への最短コスト
vector<int> prevv(MAX_V), preve(MAX_V); // 直前の頂点と辺

// fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(edge{to, cap, cost, (int)G[to].size()});
    G[to].push_back(edge{from, 0, -cost, (int)G[from].size() - 1}); // 逆辺はコストを負にする
}

// sからtへの流量gの最小費用流を求める
// 流せない場合は-1を返す
P min_cost_flow(int s, int t, int g) {
    int res = 0;
    int fee = 0;
    while (g > res) {
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
            break;
        }

        // ポテンシャルの更新
        rep(v, V) h[v] += dist[v];

        res++;          // 流す
        fee += dist[t]; // コストを加算する

        for (int v = t; v != s; v = prevv[v]) { // 最短路を逆向きにたどり、残余ネットワークを構築
            edge &e = G[prevv[v]][preve[v]];
            e.cap--;
            G[v][e.rev].cap++;
        }
    }

    return P(res, fee);
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        int idx = 0; // 暫定の頂点数

        map<int, int> sta; // (key = 到着時間, value = 頂点番号)
        sta[0] = 0;
        rep(i, n - 1) {
            int L = sta.size(); // 左側の頂点集合の要素数
            vector<P> sta_from(0);
            for (P p : sta) {
                int key = p.first;
                int value = p.second;
                idx++;
                sta_from.push_back(P(key, idx));
                add_edge(value, idx, 1, 0); // 容量1、コスト0の枝を追加（各駅、同じ到着時間となるクラスを最大1にしたいから）
            }
            sta.clear();

            int m;
            cin >> m;
            rep(j, m) {
                int x, y, c;
                cin >> x >> y >> c;
                if (!sta.count(y)) { // 新しい頂点を用意
                    idx++;
                    sta[y] = idx;
                }
                rep(k, L) {
                    P p = sta_from[k]; // p.first = 到着時間, p.second = 頂点番号
                    if (p.first > x) { // 到着時間が出発時間より遅い場合、乗り換えできない
                        break;
                    } else { // 乗り換えできる
                        add_edge(p.second, sta[y], 1, c);
                    }
                }
            }
        }
        // 最終駅について
        idx++;
        for (P p : sta) {
            int value = p.second;
            add_edge(value, idx, 1, 0); // 容量1、コスト0の枝を追加（各駅、同じ到着時間となるクラスを最大1にしたいから）
        }

        int g;
        cin >> g;

        V = ++idx; // 頂点数を確定

        // cout << "V : " << V << endl;
        P ans = min_cost_flow(1, V - 1, g);
        cout << ans.first << " " << ans.second << endl;

        // 隣接リストを初期化
        G.assign(MAX_V, vector<edge>(0));
    }
    return 0;
}