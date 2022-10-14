#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
int n, mat[maxn][maxn], vis[maxn];
void bfs(int v) {
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int k = q.front(); q.pop();
        if (vis[k]) continue;
        vis[k] = 1;
        printf("%d ", k);
        for (int i = 1; i <= n; i++) if (mat[k][i] && !vis[i]) q.push(i); 
    }
}
void dfs(int v) {
    vis[v] = 1;
    for (int i = 1; i <= n; i++) if (mat[v][i] && !vis[i]) dfs(i);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &mat[i][j]);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) if (!vis[i]) bfs(i);
    printf("\n");
    memset(vis, 0, sizeof(vis));
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            num++;
            dfs(i);
        }
    }
    printf("%d", num);
    return 0;
}