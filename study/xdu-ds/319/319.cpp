#include <bits/stdc++.h>
using namespace std;
int tree[1024*2+10], sum_tree[1024*2+10];
int n, pre[1024 + 10], in[1024 + 10], depth;
void build_tree(int root, int pos, int num) {
    if (num == 0) return;
    tree[root] = pre[pos];
    build_tree(root * 2, pos + 1, num / 2);
    build_tree(root * 2 + 1, pos + 1 + num / 2, num / 2);
}
void build_sum_tree(int k) {
    while (k > 0) {
        int pos = (1 << (k - 1)) - 1 + 1, num = 1 << (k - 1);
        for (int i = pos; i <= pos + num - 1; i++) 
            sum_tree[i] = sum_tree[i*2] + sum_tree[i*2+1] + tree[i*2] + tree[i*2+1];
        k--;
    }
}
void inorder_traverse(int root) {
    if (root > n) return;
    inorder_traverse(2 * root);
    printf("%d ", sum_tree[root]);
    inorder_traverse(2 * root + 1);
}
int main() {
    cin >> n;
    for (int i = 1;  i <= n; i++) scanf("%d", &pre[i]);
    for (int i = 1;  i <= n; i++) scanf("%d", &in[i]);   
    memset(tree, 0, sizeof(tree));
    memset(sum_tree, 0, sizeof(sum_tree));
    build_tree(1, 1, n);
    for (int i = 1; ;i++) 
        if ((1 << i) - 1 == n) {
            depth = i;
            break;
        }
    build_sum_tree(depth-1);
    inorder_traverse(1);
    return 0;
}