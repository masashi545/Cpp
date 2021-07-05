#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int cnt = 0;
    for (int i = 0; i <= A; i++) {
        if (i * 500 > X)
            break;
        else {
            for (int j = 0; j <= B; j++) {
                if (i * 500 + j * 100 > X)
                    break;
                else {
                    for (int k = 0; k <= C; k++) {
                        if (i * 500 + j * 100 + k * 50 > X)
                            break;
                        else if (i * 500 + j * 100 + k * 50 == X)
                            cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
}