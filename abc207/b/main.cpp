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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (C * D <= B) {
        cout << -1 << endl;
        return 0;
    } else {
        int count = 0;
        ll lb = A;
        ll red = 0;
        while (lb > D * red) {
            count++;
            lb += B;
            red += C;
        }
        cout << count << endl;
        return 0;
    }
}