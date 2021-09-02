#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<queue<int>> a(m);
    rep(i, m) {
        int k;
        cin >> k;
        queue<int> que;
        rep(j, k) {
            int x;
            cin >> x;
            que.push(x);
        }
        a.push_back(que);
    }

    map<int, int> mp;
    while (1) {
        rep(i, m) {
            int idx = a[i].front();
            mp[idx]++;
            a[i].pop();
            if (mp[idx] == 2) {
                mp[a[i].front()]++;
                a[i].pop();
            }
        }
    }

    return 0;
}