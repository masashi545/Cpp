#include <bits/stdc++.h>
using namespace std;

bool kaibun(deque<int> &A) {
    if (A.size() == 0 || A.size() == 1)
        return true;

    if (A.front() != A.back())
        return false;

    A.pop_front();
    A.pop_back();

    return kaibun(A);
}

int main() {
    int N;
    cin >> N;
    deque<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }

    int ans = 0;
    while (!kaibun(A)) {
        int x = A.front();
        int y = A.back();

        replace(A.begin(), A.end(), x, y);

        A.pop_front();
        A.pop_back();

        ans++;
    }

    cout << ans << endl;
}