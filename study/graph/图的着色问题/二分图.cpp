#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100
vector<int> G[MAX_V];
int vertexes;
int edges;
int color[MAX_V];  //二分图，颜色为1或-1
bool dfs(int v, int c) {
  color[v] = c;
  for (int i = 0; i < G[v].size(); i++) {
    if (color[G[v][i]] == c) return false;
    if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
  }
  return true;
}
void solve() {
  for (int i = 0; i < vertexes; i++) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        printf("No\n");
        return;
      }
    }
  }
  printf("Yes\n");
}
int main() {
  cin >> vertexes >> edges;
  for (int i = 0; i < edges; i++) {
    int m, n;
    cin >> m >> n;
    G[m].push_back(n);
    G[n].push_back(m);
  }
  solve();
}
