#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

struct BIT {
    int m;
    vector<int> bit = {0}; // [1,n]

    void init(int n) {
        m = n;
        rep(i, m) bit.push_back(0);
    }

    // 1~iまでの和を求める
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i; // 最後の1のビットを引く
        }
        return s;
    }

    // iにxを足す
    void add(int i, int x) {
        while (i <= m) {
            bit[i] += x;
            i += i & -i; // 最後の1のビットを足す
        }
    }
};
