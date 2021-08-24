#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<P> task(n);
    rep(i, n) cin >> task[i].second >> task[i].first;

    sort(task.begin(), task.end());

    int ans = 0;
    int t = 0;
    rep(i, n) {
        if (t < task[i].second) {
            ans++;
            t = task[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}

/*
in:
5
1 3
2 5
4 7
6 9
8 10

out:
3
*/