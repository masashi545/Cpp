#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 最大公約数を求める-> O(log max{a,b})
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    P p1, p2;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;

    int x = abs(p1.first - p2.first);
    int y = abs(p1.second - p2.second);

    cout << max(gcd(x, y) - 1, 0) << endl;
    return 0;
}

/*
in:
1 11
5 3

out:
3
*/