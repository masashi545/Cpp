#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }

    int ave = sum / N;
    for (int i = 0; i < N; i++) {
        if (A.at(i) >= ave)
            cout << A.at(i) - ave << endl;
        else
            cout << ave - A.at(i) << endl;
    }
}