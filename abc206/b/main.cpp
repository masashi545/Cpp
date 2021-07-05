#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int date = 1;
    int money = 0;
    while (true) {
        money += date;
        if (money >= N) {
            cout << date << endl;
            return 0;
        }
        date++;
    }
}