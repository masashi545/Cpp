#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    set<int> s;
    rep(i, n) {
        int d;
        cin >> d;
        s.insert(d);
    }

    cout << s.size() << endl;
    return 0;
}