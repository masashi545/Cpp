#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int n;
vector<priority_queue<int, vector<int>, greater<int>>> c;
vector<int> ans;
vector<bool> t;
bool ok = true;
void solve(int x) {
    cout << "solve(" << x << ")" << endl;
    if (x >= n) {
        return;
    }
    if (t[x]) {
        solve(x + 1);
    }
    if (!c[x].empty()) {
        int a = c[x].top();
        c[x].pop();
        if (!t[a])
            solve(a);
    }
    ans.push_back(x);
    t[x] = true;
    solve(x + 1);
}

int main() {
    int m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    c.resize(n);
    rep(i, m) {
        c[b[i]].push(a[i]);
    }
    t.resize(n, false);
    solve(0);

    rep(i, n) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}