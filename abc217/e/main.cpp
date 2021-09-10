#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int q;
    cin >> q;

    priority_queue<int, vector<int>, greater<int>> a;
    queue<int> que;

    rep(i, q) {
        int k;
        cin >> k;

        if (k == 1) {
            int x;
            cin >> x;
            que.push(x);
        } else if (k == 2) {
            if (a.empty()) {
                cout << que.front() << endl;
                que.pop();
            } else {
                cout << a.top() << endl;
                a.pop();
            }
        } else {
            while (!que.empty()) {
                a.push(que.front());
                que.pop();
            }
        }
    }

    return 0;
}

/*
9
1 5
1 5
1 3
2
3
2
1 6
3
2
*/