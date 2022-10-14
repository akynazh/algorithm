#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
int n, mat[maxn][maxn], vis[maxn];
void dfs1(int v) {
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++) if (mat[v][i] && !vis[i]) dfs1(i);
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
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
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