#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

const int INF = 1e9;

int dijkstra(vector<vector<int>> &G, int s, int t, int k) {
    vector<int> costs(k, INF);      // 各頂点へのの暫定最短時間
    vector<bool> visited(k, false); // 訪れた頂点集合
    priority_queue<pair<int, int>> que;

    if (s > k or t > k) {
        return 0;
    }

    int now = s;
    costs[now] = 0;
    visited[now] = true;

    while (true) {
        for (int i = 0; i < k; ++i) {
            if (!visited[i] && G[now][i] > 0) {
                if (costs[i] > G[now][i] + costs[now]) {
                    costs[i] = G[now][i] + costs[now];
                }
                que.push(make_pair(costs[i], i));
            }
        }
        if (que.empty())
            break;
        now = que.top().second;
        que.pop();
        visited[now] = true;
    }

    return (costs[t] < INF) ? costs[t] : 0;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a - 1][b - 1] = c;
    }

    int ans = 0;
    for (int s = 0; s < N; ++s) {
        for (int t = 0; t < N; ++t) {
            for (int k = 0; k < N; ++k) {
                ans += dijkstra(G, s, t, k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}