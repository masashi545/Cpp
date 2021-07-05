#include <bits/stdc++.h>
using namespace std;

bool isTravel(tuple<int, int, int> start, tuple<int, int, int> goal) {
    int t1, x1, y1;
    tie(t1, x1, y1) = start;
    //printf("t1:%d (%d, %d)\n", t1, x1, y1);
    int t2, x2, y2;
    tie(t2, x2, y2) = goal;
    //printf("t2:%d (%d, %d)\n", t2, x2, y2);
    int diff_t = t2 - t1;
    int diff_p = abs(x2 - x1) + abs(y2 - y1);

    while (diff_p <= diff_t) {
        if (diff_p == diff_t) {
            return true;
        }
        diff_t -= 2;
    }

    return false;
}

bool canTravel(queue<tuple<int, int, int>> &T) {
    if (T.size() == 1)
        return true;

    tuple<int, int, int> start, goal;
    start = T.front();
    T.pop();
    goal = T.front();

    if (isTravel(start, goal)) {
        return canTravel(T);
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    queue<tuple<int, int, int>> T;
    T.push(make_tuple(0, 0, 0));

    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        T.push(make_tuple(t, x, y));
    }

    bool res = canTravel(T);

    cout << (res ? "Yes" : "No") << endl;
}