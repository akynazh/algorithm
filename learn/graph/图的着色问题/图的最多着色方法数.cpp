#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int G[MAX][MAX];
int color[MAX];
int V, E, num_color, ccount = 0;
bool Judge_Color(int v, int col) { // 对v点用col继续涂色
  for (int i = 1; i <= V; i++)
    if (G[i][v] == 1 && color[i] == col) return false;
  return true;
}
void Solve(int v) {
  if (v > V) { // 涂色完毕
    ccount++;
    for (int i = 1; i <= V; i++) cout << color[i] << " ";
    cout << endl;
    return;
  }
  for (int i = 1; i <= num_color; i++) {
    if (Judge_Color(v, i)) { // 如果可以涂色则进行涂色
      color[v] = i;
      Solve(v + 1);
      color[v] = 0; // 回溯
    }
  }
}
int main() {
  cin >> V >> E >> num_color;
  memset(G, 0, sizeof(G));
  memset(color, 0, sizeof(color));
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }
  Solve(1); // 从第一个结点开始涂色
  cout << "解决方案有" << ccount << "种" << endl;
  return 0;
}
