#include <bits/stdc++.h>
using namespace std;

char a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    string res = "Good";
    if (a == b || b == c || c == d)
        res = "Bad";
    cout << res << endl;
}