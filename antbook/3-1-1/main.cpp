#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int binary_search(vector<int> &a, int k) {
    int l = -1;
    int r = a.size();

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int k;
    cin >> k;

    // int ans = lower_bound(a.begin(), a.end(), k) - a.begin();
    int ans = binary_search(a, k);
    cout << ans << endl;
    return 0;
}

/*
in:
5
2 3 3 5 6
3

out:
1
*/