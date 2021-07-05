#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, t) for (int i = s; i < (t); ++i)
#define rrep(i, s, t) for (int i = s; i >= (t); --i)
#define fora(x, a) for (auto &x : a)
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int m = min(min(A, B), C);
    cout << A + B + C - m << endl;
    return 0;
}