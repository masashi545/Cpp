#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> ab(N);
    for (int i = 0; i < N; i++) {
        cin >> ab.at(i).second >> ab.at(i).first; // aとbを逆にして組を形成(a->second,b->first)
    }

    // bについてソート
    sort(ab.begin(), ab.end());

    for (int i = 0; i < N; i++) {
        cout << ab.at(i).second << " " << ab.at(i).first << endl;
    }
}
