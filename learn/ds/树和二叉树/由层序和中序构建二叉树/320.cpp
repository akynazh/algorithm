#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int tree[1024 + 10], n;
int layer[1024+10], inorder[1024 + 10];
map<int, int> m; // 某序号结点在中序遍历序列中的下标
queue<P> ranges; // 可插入范围，即所在子树范围
void build_tree() {
    int layer_idx = 1; // 层序遍历序列中第一个未访问结点下标
    ranges.push(P(1, n)); // 可插入最初范围是全局
    for (int depth = 1; depth <= 10; depth++) { // 从第一层开始遍历，且题目已知最多有10层
        if (layer_idx > n) break;
        int pos = (1 << (depth-1)) - 1 + 1; // 该层第一个结点所在二叉树的下标
        for (int j = 0; j < 1 << (depth-1); j++) { // 当前层最多个数
            P p = ranges.front();
            ranges.pop();
            if (p.first > p.second) { // 左下标大于右下标表示已经没有孩子了
                // 放入两个空集
                ranges.push(P(1, 0));
                ranges.push(P(1, 0));
                continue;
            } 
            int my_pos = m[layer[layer_idx]]; // 层序遍历中的第一个未访问结点所在中序遍历序列中的下标
            if (my_pos >= p.first && my_pos <= p.second) { // 如果在插入范围内
                tree[pos+j] = layer[layer_idx]; // 将该结点纳入二叉树
                layer_idx++;
                 // 生成该结点左右子树的可插入范围
                ranges.push(P(p.first, my_pos-1));
                ranges.push(P(my_pos+1, p.second));
            }

        }
    }
}
void get_leaves(int root) {
    if (tree[2*root] == 0 && tree[2*root+1] == 0) {
        printf("%d ", tree[root]);
        return;
    }
    // 从左到右输出
    if (tree[root * 2]) get_leaves(root * 2);
    if (tree[root * 2 + 1]) get_leaves(root * 2 + 1);
}
void pre_traverse(int root) {
    if (!tree[root]) return;
    printf("%d ", tree[root]);
    pre_traverse(root * 2);
    pre_traverse(root * 2 + 1);
}
void post_traverse(int root) {
    if (!tree[root]) return;
    post_traverse(root * 2);
    post_traverse(root * 2 + 1);
    printf("%d ", tree[root]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &layer[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &inorder[i]);
        m[inorder[i]] = i;
    }
    memset(tree, 0, sizeof(tree));
    build_tree();
    get_leaves(1);
    printf("\n");
    pre_traverse(1);
    printf("\n");
    post_traverse(1);
    return 0;
}