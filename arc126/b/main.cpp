#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    vector<P> line(m);
    rep(i, m) {
        P p;
        cin >> p.first >> p.second;
        line[i] = p;
    }

    sort(line.begin(), line.end());

        return 0;
}