#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, start, end) for (int i = start; i < (end); ++i)
using ll = long long;
using P = pair<int, int>;

void swap(vector<int> &a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

// クイックソート
void quickSort(vector<int> &a, int left, int right) {
    int pivot = a[(left + right) / 2]; // ピボットを選ぶ
    int i = left;
    int j = right;

    while (true) {
        while (a[i] < pivot) // 左から走査し、ピボット以上の要素を見つける　
            i++;
        while (a[j] > pivot) // 右から走査し、ピボット以下の要素を見つける　
            j--;

        // i>=jならば終了
        if (i >= j)
            break;

        // i<jならばスワップ
        swap(a, i, j);

        // 次に移行
        i++;
        j--;
    }

    cout << endl;
    cout << "left=" << left << endl;
    cout << "right=" << right << endl;
    cout << "pivot=" << pivot << endl;
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
    rep(i, 0, a.size()) cout << a[i] << " ";
    cout << endl;

    if (left < i - 1)
        quickSort(a, left, i - 1);

    if (j + 1 < right)
        quickSort(a, j + 1, right);
}

// マージソート
void mergeSort(vector<int> &a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        // Merge
        queue<int> q1, q2;
        rep(i, left, mid + 1) q1.push(a[i]);
        rep(i, mid + 1, right + 1) q2.push(a[i]);

        rep(i, left, right + 1) {
            if (q1.empty()) {
                a[i] = q2.front();
                q2.pop();
            } else if (q2.empty()) {
                a[i] = q1.front();
                q1.pop();
            } else if (q1.front() < q2.front()) {
                a[i] = q1.front();
                q1.pop();
            } else {
                a[i] = q2.front();
                q2.pop();
            }
        }
        cout << endl;
        cout << "left=[" << left << "," << mid << "]" << endl;
        cout << "right=[" << (mid + 1) << "," << right << "]" << endl;
        rep(i, 0, a.size()) cout << a[i] << " ";
        cout << endl;
    }
}

// バブルソート
void bubbleSort(vector<int> &a) {
    int n = a.size();
    bool swp = true;
    for (int i = 0; i < n && swp; ++i) {
        swp = false;
        rep(j, 0, n - 1 - i) {
            if (a[j] > a[j + 1]) {
                swp = true;
                swap(a, j, j + 1);
            }
        }
        if (swp) {
            cout << endl;
            rep(i, 0, n) cout << a[i] << " ";
            cout << endl;
        }
    }
}

// ヒープソート
// ヒープ条件をみたすように並べ替える
void heapify(vector<int> &a, int n, int i) { // n:考慮する範囲、i:注目している頂点
    int idx = i;                             // 最大の値を親に
    int left = 2 * i + 1;                    // 左の子
    int right = 2 * i + 2;                   // 右の子

    // 子の方が大きい場合は親交代
    if (left < n && a[idx] < a[left])
        idx = left;
    if (right < n && a[idx] < a[right])
        idx = right;

    // 親が交代した場合
    if (idx != i) {
        swap(a, idx, i);
        heapify(a, n, idx);
    }
}

void heapSort(vector<int> &a) {
    int n = a.size();
    for (int i = n - 1; i >= 0; --i) // ヒープを構成
        heapify(a, n, i);

    cout << endl;
    cout << "heaped:" << endl;
    rep(i, 0, n) cout << a[i] << " ";
    cout << endl;

    for (int i = n - 1; i >= 0; --i) {
        swap(a, 0, i);    // 根と最深最右(末尾)の要素をスワップ->以降、末尾以外を考慮する
        heapify(a, i, 0); // ヒープを回復

        cout << endl;
        rep(i, 0, n) cout << a[i] << " ";
        cout << endl;
    }
}

// 挿入ソート
void insertSort(vector<int> &a) {
    rep(i, 1, a.size()) {
        cout << endl;
        cout << "insert:a[" << i << "]=" << a[i] << endl;

        for (int j = i; j > 0; j--) {
            if (a[j - 1] > a[j])
                swap(a, j - 1, j);
            else
                break;
        }
        rep(i, 0, a.size()) cout << a[i] << " ";
        cout << endl;
    }
}

// バケットソート
void bucketSort(vector<int> &a) {
    int r = 0;
    for (int x : a)
        r = max(r, x);
    vector<int> count(r + 1);  // 値ごとの出現回数(バケツ)とりうる値は[0,r]
    vector<int> offset(r + 1); // ソート後配列の値ごとの開始位置
    vector<int> ans(a.size());

    // 出現回数を数える(バケツに入れていく)
    for (int x : a)
        count[x]++;

    // 開始位置計算
    offset[0] = 0;
    rep(i, 1, r + 1) offset[i] = offset[i - 1] + count[i - 1];

    // 値の小さいバケツから順に並べる
    for (int x : a) {
        ans[offset[x]] = x;
        offset[x]++;
    }
    cout << endl;
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}

// 基数ソート
void radixSort(vector<int> &a, int k) { // k:最大桁数
    vector<vector<queue<int>>> bucket(2, vector<queue<int>>(10));

    for (int x : a) {
        bucket[0][x % 10].push(x);
    }
    int rdx = 10;
    rep(i, 1, k) {
        int b = (i - 1) % 2;
        int c = i % 2;
        rep(j, 0, 10) {
            while (!bucket[b][j].empty()) {
                int x = bucket[b][j].front();
                bucket[b][j].pop();
                int y = int(x / rdx) % 10;
                bucket[c][y].push(x);
            }
        }
        rdx *= 10;
    }

    int idx = 0;
    int d = (k - 1) % 2;
    rep(i, 0, 10) {
        while (!bucket[d][i].empty()) {
            a[idx] = bucket[d][i].front();
            bucket[d][i].pop();
            idx++;
        }
    }
    cout << endl;
    rep(i, 0, a.size()) cout << a[i] << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    // quickSort(a, 0, n - 1);
    // mergeSort(a, 0, n - 1);
    // bubbleSort(a);
    // heapSort(a);
    // insertSort(a);
    // bucketSort(a);
    // radixSort(a, 3);
    return 0;
}
// test case
/*
10
3 8 5 2 1 7 6 9 4 10 

20
123 527 732 512 973 426 994 863 206 885 258 44 215 300 770 137 77 681 359 905
*/