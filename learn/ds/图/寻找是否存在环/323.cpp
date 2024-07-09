#include <bits/stdc++.h> // 适用于无向图中判断是否有环的算法：DFS的思想
using namespace std;
const int maxn = 100 + 10;
int mat[maxn][maxn], vis[maxn];
int n, num;
vector<int> ans;
int dfs(int v) {
    vis[v] = 1;
    for (int i = 0; i < num; i++) if (mat[v][i]) {
        if (vis[i] || dfs(i)) return 1; // 该连通子图新纳入的结点与原连通子图中的某一结点有边，即产生了环
    }
    return 0;
}
int main() {
    scanf("%d", &n);
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            for (int k = 0; k < num; k++)
                scanf("%d", &mat[j][k]);
        memset(vis, 0, sizeof(vis));
        int flag = 0; // 无环标志
        for (int j = 0; j < num; j++) {
            if (!vis[j]) flag = dfs(j); // 因为是无向图，所以每开始一次新的递归即进入一个新的连通子图，一定不会访问到其他连通子图的结点
            if (flag) break; // 如果在该连通子图中找到环则直接结束递归
        } 
        ans.push_back(flag);
    }
    for (int i = 0; i < n; i++) printf("%d", ans[i]);
    return 0;
}