#include <bits/stdc++.h>
using namespace std;
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
    T = new Tree(-1);
    root = new Tree();
    T->l = root; // 建立联系必须从父节点结点联系
    // 如果是 T->l = root, root = new Tree()则无法建立联系
    // T->l = new Tree(); root = T->l; root = new Tree()也失败

    int n, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Tree *pa = T, *idx = root; // pa指向父节点，idx指向当前节点
        scanf("%d", &v);
        if (i == 0) { // 如果是输入的第一个数即根节点
            root->val = v;
            printf("-1\n");
            continue;
        }
        while (idx) {
            pa = idx; // pa指向父节点
            if (v < idx->val) { // 从父节点建立联系！
                if (!idx->l) {idx->l = new Tree(v); break;}
                idx = idx->l;
            } else {
                if (!idx->r) {idx->r = new Tree(v); break;}
                idx = idx->r;
            }
        }
        printf("%d\n", idx->val);
    }
    return 0;
}