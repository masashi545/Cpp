#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> D;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        D.insert(d);
    }

    cout << D.size() << endl;
}