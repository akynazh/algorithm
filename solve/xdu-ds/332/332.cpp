#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
struct Node {
    int val, l, r;
};
int n, root;
Node nodes[maxn];
bool dfs(int t, int pa, int dir) {
    int l = nodes[t].l, r = nodes[t].r;
    if (l == 0 && r == 0) return true;
    if (l != 0) {
        if (dir == -1 && nodes[l].val > pa) return false;
        if (dir == 1 && nodes[l].val < pa) return false;
        dfs(l, pa, dir);
    }
    if (r != 0) {
        if (dir == -1 && nodes[r].val > pa) return false;
        if (dir == 1 && nodes[r].val < pa) return false;
        dfs(r, pa, dir);
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &root);
    for (int i = 1; i <= n; i++) 
        scanf("%d%d%d", &nodes[i].val, &nodes[i].l, &nodes[i].r);
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        int l = nodes[i].l, r = nodes[i].r, val = nodes[i].val;
        if (l != 0 && (nodes[l].val > val || !dfs(l, val, -1))) {flag = 0; break;}
        if (r != 0 && (nodes[r].val < val || !dfs(r, val, 1))) {flag = 0; break;}
    }
    if (flag) printf("true");
    else printf("false");
    return 0;
}