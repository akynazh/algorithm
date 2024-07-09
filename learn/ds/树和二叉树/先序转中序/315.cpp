#include <bits/stdc++.h>
using namespace std;
struct Tree {
    Tree *left, *right;
    int value; // 结点值对应下标
    Tree() {left = NULL; right = NULL;}
};
string str;
Tree* tree;
int idx = 0;
void build_tree(Tree*& root) { 
    // 关键点：必须是Tree*&，该函数里root需要new所以需要传指针类型，所以必须传递指针的指针
    if (str[idx] == '#' ||  idx >= (int)str.length()) return;
    else {
        root = new Tree();
        root->value = idx;
        idx++;
        build_tree(root->left);
        idx++;
        build_tree(root->right);
    }
}
void inorder(Tree* root) {
    if (root->left) inorder(root->left);
    if (root->value < (int)str.length() && root->value >= 0) printf("%c ", str[root->value]);
    if (root->right) inorder(root->right);
}
int main() {
    cin >> str;
    tree = new Tree();
    build_tree(tree);
    inorder(tree);
    return 0;
}