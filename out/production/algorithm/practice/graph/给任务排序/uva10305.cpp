# include <bits/stdc++.h>
using namespace std;
int n, m, t;
const int maxn = 100 + 10;
int G[maxn][maxn];
int ans[maxn];
int vis[maxn];
// get input
bool test() {
    scanf("%d%d", &n, &m);
    t = n;
    if (n == 0 && m == 0) return false;
    memset(G, 0, sizeof(G));
    memset(vis, 0, sizeof(vis)); // -1 标记该轮DFS已访问 0 未访问 1 已访问
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0) break;
        G[a][b] = 1;
    }
    return true;
}
// 对当前结点进行一次深搜
bool dfs(int u) {
    vis[u] = -1; // 该轮DFS标记访问过了，在往下DFS时可以检测是否出现环
    for (int i = 1; i <= n; i++) {
        if (G[u][i]) {
            if (vis[i] == -1) return false; // 出现环
            else if (!vis[i] && !dfs(i)) return false; // 递归下去发现环
            // 当vis[i]==1时不用访问
        }
    }
    vis[u] = 1; // 标记已经访问过了
    ans[t--] = u; // 记录拓扑序列, 以为从任一点DFS，最终都会达到最深处，即达到最大值处。
    return true;
}
bool toposort() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { // 若该结点及其子孙未被访问
            if (!dfs(i)) return false; // 若访问失败（不是DAG）
        }
    }
    return true;
} 
int main() {
    while (test()) {
        if (toposort()) {
            for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}