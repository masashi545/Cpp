#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push(a);
    }

    int diff = 0;
    while (!A.empty()) {
        diff += A.top();
        A.pop();
        if (!A.empty()) {
            diff -= A.top();
            A.pop();
        }
    }

    cout << diff << endl;
}