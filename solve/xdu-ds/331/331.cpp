#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int val;
    Tree *l, *r;
    Tree(int v) {
        val = v;
        l = r = NULL;
    }
    Tree() {l = r = NULL;}
};
void pre(Tree*& root) {
    printf("%d ", root->val);
    if (root->l) pre(root->l);
    if (root->r) pre(root->r);
}
void in(Tree*& root) {
    if (root->l) in(root->l);
    printf("%d ", root->val);
    if (root->r) in(root->r);
}
void post(Tree*& root) {
    if(root->l) post(root->l);
    if(root->r) post(root->r);
    printf("%d ", root->val);
}
int main() {
    int n, v;
    Tree *tree = new Tree();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        Tree *idx = tree;
        if (i == 0) {tree->val = v; continue;}
        while (idx) {
            if (v == idx->val) break;
            if (v < idx->val) {
                if (!idx->l) {idx->l = new Tree(v); break;}
                idx = idx->l;
            } else {
                if (!idx->r) {idx->r = new Tree(v); break;}
                idx = idx->r;
            }
        }
    }
    pre(tree);
    printf("\n");
    in(tree);
    printf("\n");
    post(tree);
    return 0;
}