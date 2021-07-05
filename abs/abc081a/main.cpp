#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b, c;
    cin >> a >> b >> c;

    int sum = 0;
    if (a == '1')
        sum++;
    if (b == '1')
        sum++;
    if (c == '1')
        sum++;

    cout << sum << endl;
}