#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    rep(i, n) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        p[i] = p1 + p2 + p3;
        q[i] = p[i];
    }

    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    int goal = q[k - 1]; // 3日目の時点でk位の人の点数

    rep(i, n) {
        cout << ((p[i] + 300 >= goal) ? "Yes" : "No") << endl;
    }
    return 0;
}