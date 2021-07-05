#include <bits/stdc++.h>
using namespace std;

// 木構造のデータ型
struct tree {
    // 木の節点の種類(葉or枝)
    enum class nkind { // enum:列挙体 -> 列挙したいずれかの値を持つオブジェクト
        LEAF,
        BRANCH
    } tag; // 構造体変数の宣言

    // 木の節点の情報
    union ndata { // union:共用体 -> 異なる型のデータを同じ領域に重ね合わせて、ひとつのオブジェクトとして扱う
        // 葉 -> 値も子も持たない(葉に値を持たせることもできるように構造体を定義しておく)
        struct leaf {
            int dummy;
        } lf;
        // 枝 -> 値と左右の子を持つ(左右の子がどちらも葉である枝が、グラフ上の「葉」となる)
        struct branch {
            struct tree *left; // 再帰的なデータ構造をとるためには、ポインタを使う必要がある
            int value;         // データ領域の大きさが図れなくなるから
            struct tree *right;
        } br;
    } dat;
};

// 新しい葉を作成する関数
struct tree *newleaf() {
    struct tree *n = (struct tree *)malloc(sizeof(struct tree));
    n->tag = tree::nkind::LEAF;
    return n;
}

// 新しい枝を作成する関数
struct tree *newbranch(struct tree *left, int value, struct tree *right) {
    // ポインタを返す関数は、ヒープ領域を確保して、そこに返り値を格納しなければならない
    // スタック領域だと関数の実行が終わった時点で領域が解放されてしまうため、値が削除されてしまう
    // 枝1つ分のヒープ領域を確保して、木のデータ型へのポインタを宣言
    struct tree *n = (struct tree *)malloc(sizeof(struct tree));
    // ポインタを介して、値を格納
    n->tag = tree::nkind::BRANCH; // n->tag は、(*n).tag と同じ意味
    n->dat.br.left = left;
    n->dat.br.value = value;
    n->dat.br.right = right;
    return n;
}

// 与えられた木に与えられた値の節点があるかどうかを判定する関数
bool find(struct tree *t, int n) {
    if (t->tag == tree::nkind::LEAF)
        return false;
    else { // if (t->tag == tree::nkind::BRANCH)
        struct tree::ndata::branch *b = &(t->dat.br);
        if (n == b->value)
            return true;
        else if (n < b->value)
            return find(b->left, n);
        else // if (b->value < n)
            return find(b->right, n);
    }
}

// 与えられた木に与えられた値の節点を追加した木を返す関数
struct tree *insert(struct tree *t, int n) {
    if (t->tag == tree::nkind::LEAF)
        return newbranch(newleaf(), n, newleaf());
    else { // if (t->tag == tree::nkind::BRANCH)
        struct tree::ndata::branch *b = &(t->dat.br);
        if (n == b->value)
            return t;
        else if (n < b->value)
            return newbranch(insert(b->left, n), b->value, b->right);
        else // if (b->value < n)
            return newbranch(b->left, b->value, insert(b->right, n));
    }
}

// 与えられた木の節点の値で最小のものを返す関数
int min(struct tree *t) {
    if (t->tag == tree::nkind::LEAF) { // 木が葉だけだったらエラー
        cout << "not have any nodes" << endl;
        return -10000;
    }

    struct tree::ndata::branch *b = &(t->dat.br);
    if (b->left->tag == tree::nkind::LEAF)
        return b->value;
    else
        return min(b->left);
}

// 与えられた木から与えられた値の節点を削除した木を返す関数
struct tree *delete_(struct tree *t, int n) {
    if (t->tag == tree::nkind::LEAF)
        return t;
    else {
        struct tree::ndata::branch *b = &(t->dat.br);
        if (n == b->value)
            if (b->left->tag == tree::nkind::LEAF) {
                if (b->right->tag == tree::nkind::LEAF)
                    return newleaf();
                else
                    return b->right;
            } else {
                if (b->right->tag == tree::nkind::LEAF)
                    return b->left;
                else
                    return newbranch(b->left, min(b->right), delete_(b->right, min(b->right)));
            }

        else if (n < b->value)
            return newbranch(delete_(b->left, n), b->value, b->right);

        else // if (b->value < n)
            return newbranch(b->left, b->value, delete_(b->right, n));
    }
}

int main() {
}