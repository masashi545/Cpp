#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> E(n); // 枝集合
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        E[a - 1].insert(b - 1);
        E[b - 1].insert(a - 1);
    }

    vector<int> V(n); // 頂点集合
    rep(i, n) V[i] = i;

    int ans = 0;
    do {
        bool allcnct = true; // 全ての頂点が連結しているか
        rep(i, n - 1) {
            if (!E[V[i]].count(V[i + 1])) { // 頂点iが頂点i+1と接続しているか
                allcnct = false;
                break;
            }
        }
        if (allcnct)
            ans++;

    } while (next_permutation(V.begin() + 1, V.end())); // 先頭を除いた順列を列挙

    cout << ans << endl;
    return 0;
}