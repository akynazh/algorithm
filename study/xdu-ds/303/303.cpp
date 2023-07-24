#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int graph[maxn+1][maxn+1];
int vis[maxn+1];
int n, m, cnt = 1;
vector<int> num;
void dfs(int v) {
    vis[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && graph[v][i]) {
            cnt++;
            dfs(i);
        }
    }
}
int main() {
    memset(graph, 0, sizeof(graph));
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i);
            num.push_back(cnt);
            cnt = 1;
        }
    }
    sort(num.begin(), num.end());
    cout << count << endl;
    for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
    return 0;
}