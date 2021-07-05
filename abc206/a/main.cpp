#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x = int(1.08 * N);
    cout << ((x == 206) ? "so-so" : ((x < 206) ? "Yay!" : ":(")) << endl;
}