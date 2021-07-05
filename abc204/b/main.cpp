#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 10)
            count += x - 10;
    }

    cout << count << endl;
}