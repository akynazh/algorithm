/*
经过图中所有边且每边仅通过一次的通路称为欧拉通路 相应的回路称为欧拉回路
具有欧拉回路的图称为欧拉图（Euler Graph）
具有欧拉通路而无欧拉回路的图称为半欧拉图
*/
/*
重要结论：
若为无向连通欧拉图
1. 除出起点终点外其他点的度数必须为偶数，即奇点数必须小于等于2个 （度数为奇数的点成为奇点）
2. 若有两个奇点，则必须从一个奇点出发，到另一个奇点终止
3. 若奇点不存在，则可以从任意点出发，最终一定会回到该点

若为有向连通欧拉图
1.最多只能有两个结点入度不等于出度
2.起点：出度比入度大一 终点：入度比出度大一
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int G[maxn][maxn];
int vis[maxn][maxn];
int n;
void euler(int u) {
    for (int v = 0; v < n; v++) {
        if (G[u][v] && !vis[u][v]) {
            vis[u][v] = vis[v][u] = 1;
            euler(v);
            printf("%d %d\n", u, v);
        }
    }
}
int main() {
    euler(0);
    return 0;
}