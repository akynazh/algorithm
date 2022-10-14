#include <bits/stdc++.h>
using namespace std;
// 关于动态构树的问题！
struct Tree {
    int val;
    Tree *l, *r;
    Tree(int v) {
        val = v;
        l = r = NULL;
    }
    Tree(){l = r = NULL;}
};
int main() {
    Tree *T, *root;
    // 正确构造，从父节点建立联系
    // T = new Tree(-1);
    // root = new Tree();
    // T->l = root;
    // root->val = 18;
    // cout << T->l->val;

    // 相当于以上正确构造，只是没用到root指针域
    // T = new Tree(-1);
    // T->l = new Tree(18);
    // cout << T->l->val;

    // 错误构造，从子节点自己new出的无法与父节点建立联系
    // T = new Tree(-1);
    // root = T->l;
    // root = new Tree(18); 
    // cout << T->l->val;
    return 0;
}