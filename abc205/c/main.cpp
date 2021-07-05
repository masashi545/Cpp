#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    string res = "";
    if (C % 2 == 0) {
        res = (abs(A) == abs(B)) ? "=" : ((abs(A) < abs(B)) ? "<" : ">");
    }
    if (C % 2 == 1) {
        res = (A == B) ? "=" : ((A < B) ? "<" : ">");
    }

    cout << res << endl;
}
