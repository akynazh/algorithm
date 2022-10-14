#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int city[maxn+10][maxn+10];
int vis[maxn+10];
int n, m;
void dfs(int v) {
    for (int i = 1; i <= n; i++) if (city[v][i] && !vis[i]) {
        vis[i] = 1;
        dfs(i);
    }
}
int main() {
    memset(city, 0, sizeof(city));
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0;  i < m; i++) {
        scanf("%d%d", &a, &b);
        city[a][b] = city[b][a] = 1;
    }
    int conn = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            conn++;
            dfs(i);
        }
    }
    printf("%d", conn-1);
}