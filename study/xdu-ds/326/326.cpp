#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 1;
int mat[maxn][maxn], vis[maxn], dis[maxn];
int m, n, k;
int Dijkstra(int start) {
    vis[start] = 1; dis[start] = 0;
    for (int i = 1; i <= n; i++) 
        if (mat[start][i]) 
            dis[i] = mat[start][i];
    for (int i = 1; i <= n; i++) {
        int mmin = 1000 + 10, k = 0;
        for (int i = 1; i <= n; i++) if (!vis[i] && dis[i] < mmin) {
            mmin = dis[i];
            k = i;
        } 
        if (k == 0) break;
        vis[k] = 1;
        for (int i = 1; i <= n; i++) if (mat[k][i] && !vis[i]) {
            if (mat[k][i] + mmin < dis[i]) dis[i] = mat[k][i] + mmin;
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) return -1;
    int mmax = -1;
    for (int i = 1; i <= n; i++) if (dis[i] > mmax) mmax = dis[i];
    return mmax;
}
int main() {
    scanf("%d%d%d", &m, &n, &k);
    memset(mat, 0, sizeof(mat));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    int from, to, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &from, &to, &w);
        mat[from][to] = w;
    }
    printf("%d", Dijkstra(k));
    return 0;
}