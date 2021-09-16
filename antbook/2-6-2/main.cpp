#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 最大公約数を求める-> O(log max{a,b})
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ax + by = gcd(a,b) を満たす x,yを求める
P extgcd(int a, int b) {
    if (b == 0) {
        return P(1, 0);
    }
    P p = extgcd(b, a % b);
    swap(p.first, p.second);
    p.second -= (a / b) * p.first;
    return p;
}

int main() {
    int a, b;
    cin >> a >> b;

    if (gcd(a, b) != 1) {
        cout << -1 << endl;
        return 0;
    }

    P p = extgcd(a, b);
    if (p.first >= 0) {
        cout << p.first << " " << 0 << " ";
    } else {
        cout << 0 << " " << -p.first << " ";
    }

    if (p.second >= 0) {
        cout << p.second << " " << 0 << " ";
    } else {
        cout << 0 << " " << -p.second << " ";
    }

    return 0;
}

/*
in:
4 11

out:
3 0 0 1
*/