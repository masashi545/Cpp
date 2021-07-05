#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int pls = 0;
    int mns = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '+')
            pls++;
        else if (S.at(i) == '-')
            mns++;
    }

    cout << pls - mns + 1 << endl;
}
