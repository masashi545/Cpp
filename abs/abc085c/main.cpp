#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    tuple<int, int, int> tpl(-1, -1, -1);
    bool finish = false;
    for (int i = 0; i <= N; i++) {
        if (i * 10000 > Y || finish)
            break;

        for (int j = 0; j <= N - i; j++) {
            if (i * 10000 + j * 5000 + (N - i - j) * 1000 > Y)
                break;

            if (i * 10000 + j * 5000 + (N - i - j) * 1000 == Y) {
                tpl = make_tuple(i, j, N - i - j);
                finish = true;
                break;
            }
        }
    }
    int a, b, c;
    tie(a, b, c) = tpl;
    cout << a << " " << b << " " << c << endl;
}