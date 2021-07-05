#include <bits/stdc++.h>
using namespace std;

bool partitionable(string &str) {
    int l = str.size();
    if (l == 0)
        return true;

    if (l < 5)
        return false;

    if (l < 6) {
        if (str == "dream" || str == "erase")
            return true;
        else
            return false;
    }

    if (l < 7) {
        if (str == "eraser")
            return true;
        else
            return false;
    }

    if (l < 8) {
        if (str == "dreamer")
            return true;
        else
            return false;
    }

    if (str.substr(l - 5, 5) == "dream" || str.substr(l - 5, 5) == "erase") {
        str.erase(l - 5);
        return partitionable(str);
    }

    if (str.substr(l - 6, 6) == "eraser") {
        str.erase(l - 6);
        return partitionable(str);
    }

    if (str.substr(l - 7, 7) == "dreamer") {
        str.erase(l - 7);
        return partitionable(str);
    }

    return false;
}

int main() {
    string S;
    cin >> S;

    bool res = partitionable(S);

    cout << (res ? "YES" : "NO") << endl;
}