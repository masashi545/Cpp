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

// 最小公倍数を求める
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}