#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    sort(x.begin(), x.end());

    int lb = 0;
    int ub = INF;

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        // mid以上の間隔で牛舎に入れることができるか
        bool ok = true;
        int last = 0; // 最後に牛を入れた牛舎　まず先頭の牛舎に入れる
        for (int i = 1; i < m; ++i) {
            int crt = last + 1;
            while (crt < n && x[crt] - x[last] < mid) {
                crt++;
            }
            if (crt == n) // 入れることができる牛舎がなくなったのでfalse
                ok = false;
            last = crt;
        }
        if (ok)
            lb = mid;
        else
            ub = mid;

        // cout << "lb=" << lb << ", ub=" << ub << endl;
    }

    cout << lb << endl;
    return 0;
}

/*
in:
5
3
1 2 8 4 9   

out:
3
*/