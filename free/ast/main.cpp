#include <bits/stdc++.h>
using namespace std;

// 抽象構文木のデータ型
struct ast {
    // 木の節点の種類(葉or枝)
    enum nkind {
        LEAF, // 葉
        S,    // 加算の枝
        M     // 乗算の枝
    } tag1;

    // 木の節点の情報
    union ndata {
        // 葉　-> 整数定数または変数
        struct leaf {
            enum lkind {
                CONS, // 整数定数
                VAR   // 変数
            } tag2;
            union ldata {
                int cons;
                string var;
            } value;
        } lf;
        // 枝 -> 値はなくて、枝に種類がある
        struct branch {
            struct ast *left;
            struct ast *right;
        } br;
    } dat;
};

// 新しいLeaf(整数定数)を作成する関数
struct ast *newLeaf(int x) {
    struct ast *n = (struct ast *)malloc(sizeof(struct ast));
    n->tag1 = ast::nkind::LEAF;
    n->dat.lf.tag2 = ast::ndata::leaf::lkind::CONS;
    n->dat.lf.value.cons = x;
    return n;
}

// 新しいLeaf(変数)を作成する関数
struct ast *newLeaf(string x) {
    struct ast *n = (struct ast *)malloc(sizeof(struct ast));
    n->tag1 = ast::nkind::LEAF;
    n->dat.lf.tag2 = ast::ndata::leaf::lkind::VAR;
    n->dat.lf.value.var = x;
    return n;
}

// 新しい加算の枝を作成する関数
struct ast *newS(struct ast *left, struct ast *right) {
    // 枝1つ分のヒープ領域を確保して、木のデータ型へのポインタを宣言
    struct ast *n = (struct ast *)malloc(sizeof(struct ast));
    // ポインタを介して、値を格納
    n->tag1 = ast::nkind::S;
    n->dat.br.left = left;
    n->dat.br.right = right;
    return n;
}

// 新しい乗算の枝を作成する関数
struct ast *newM(struct ast *left, struct ast *right) {
    // 枝1つ分のヒープ領域を確保して、木のデータ型へのポインタを宣言
    struct ast *n = (struct ast *)malloc(sizeof(struct ast));
    // ポインタを介して、値を格納
    n->tag1 = ast::nkind::M;
    n->dat.br.left = left;
    n->dat.br.right = right;
    return n;
}

// 整数定数0に対して式を単純化する関数
struct ast *simpl0(struct ast *t) {
    if (t->tag1 == ast::nkind::LEAF) // 葉の場合
        return t;

    else if (t->tag1 == ast::nkind::S) { // 加算の枝の場合
        struct ast *l = simpl0(t->dat.br.left);
        struct ast *r = simpl0(t->dat.br.right);
        free(t);

        if ((l->tag1 == ast::nkind::LEAF)                        // 左の枝が、葉で
            && (l->dat.lf.tag2 == ast::ndata::leaf::lkind::CONS) // 整数定数で
            && (l->dat.lf.value.cons == 0)) {                    // 0だったら
            free(l);                                             // 単純化する
            return r;
        }

        else if ((r->tag1 == ast::nkind::LEAF)                        // 右の枝が、葉で
                 && (r->dat.lf.tag2 == ast::ndata::leaf::lkind::CONS) // 整数定数で
                 && (r->dat.lf.value.cons == 0)) {                    // 0だったら
            free(r);                                                  // 単純化する
            return l;
        }

        else                   // それ以外の場合
            return newS(l, r); // 左右の枝どちらとも単純化する
    }

    else { // 乗算の枝の場合
        struct ast *l = simpl0(t->dat.br.left);
        struct ast *r = simpl0(t->dat.br.right);
        free(t);

        if (((l->tag1 == ast::nkind::LEAF)                           // 左の枝が、葉で
             && (l->dat.lf.tag2 == ast::ndata::leaf::lkind::CONS)    // 整数定数で
             && (l->dat.lf.value.cons == 0))                         // 0だったら
                                                                     // または
            || ((r->tag1 == ast::nkind::LEAF)                        // 右の枝が、葉で
                && (r->dat.lf.tag2 == ast::ndata::leaf::lkind::CONS) // 整数定数で
                && (r->dat.lf.value.cons == 0))) {                   // 0だったら

            free(l); // 単純化する
            free(r);
            return newLeaf(0);
        }

        else                   // それ以外の場合
            return newM(l, r); // 左右の枝どちらとも単純化する
    }
}

string ast_to_string(struct ast *t) {
    if (t->tag1 == ast::nkind::LEAF) {
        if (t->dat.lf.tag2 == ast::ndata::leaf::lkind::CONS) {
            return to_string(t->dat.lf.value.cons);
        } else {
            return t->dat.lf.value.var;
        }
    }

    else { // if (t->tag1 == tree::nkind::BRANCH)
        string l = "br(" + ast_to_string(t->dat.br.left);
        string r = ast_to_string(t->dat.br.right) + ")";
        if (t->tag1 == ast::nkind::S)
            return l + ", +, " + r;
        else
            return l + ", *, " + r;
    }
}

int main() {
    struct ast *t1 = newM(newLeaf(4), newLeaf("x"));
    struct ast *t2 = newS(newLeaf("y"), newLeaf(0));
    struct ast *t3 = newS(t1, t2);

    cout << ast_to_string(t3) << endl;
    cout << ast_to_string(simpl0(t3)) << endl;
    // cout << ast_to_string(t3) << endl; // コンパイルエラー！
    // cout << ast_to_string(t2) << endl; // コンパイルエラー！
}