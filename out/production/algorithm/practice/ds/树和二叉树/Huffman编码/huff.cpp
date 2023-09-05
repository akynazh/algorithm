#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
struct node { // huffman结点元素
    int parent, index, w;
    node(int a, int b, int c) {
        parent = a;
        index = b;
        w = c;
    }
    node() {}
};
struct cmp {
    bool operator() (node a, node b) {return a.w > b.w;}
};
int n, ans = 0;
node huff[2*maxn+1]; // huff顶点数为2n-1 从1开始
priority_queue<node, vector<node>, cmp> qnodes;
void build() {
    scanf("%d", &n);
    int w;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w);
        huff[i] = node(0, i, w);
        qnodes.push(node(0, i, w));
    }
    for (int i = n+1; i <= 2*n-1; i++) {
        // 取出两最小权结点
        node n1 = qnodes.top(); qnodes.pop();
        node n2 = qnodes.top(); qnodes.pop();
        // 将新结点放入优先队列
        qnodes.push(node(0, i, n1.w+n2.w));
        // 将两最小权结点的父结点置为i
        huff[n1.index].parent = huff[n2.index].parent = i;
        // 将新结点纳入huffman树
        huff[i] = node(0, i, n1.w+n2.w);
    }
}
void getWPL() {
    for (int i = 1; i <= n; i++) {
        int len = 1, tag = i;
        while (huff[tag].parent != 2*n-1) {
            len++;
            tag = huff[tag].parent;
        }
        ans += len * huff[i].w;
    }
}
int main() {
    build();
    getWPL();
    printf("%d", ans);
    return 0;
}