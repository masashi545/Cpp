#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> G(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    queue<int> que;         // 調べる街
    vector<int> dis(n, -1); // 0番目の街からの距離
    que.push(0);            // まず、0番目の街から
    dis[0] = 0;
    while (!que.empty()) {
        int t = que.front(); // 今いる街
        que.pop();
        for (int x : G[t]) { // 今いる街と隣接している街
            if (dis[x] == -1) {
                dis[x] = dis[t] + 1;
                que.push(x);
            }
        }
    }

    rep(i, q) {
        int c, d;
        cin >> c >> d;
        if (dis[c - 1] % 2 == dis[d - 1] % 2) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }

    return 0;
}