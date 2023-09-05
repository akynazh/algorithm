#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int G[MAX][MAX];
int color[MAX];
int V, E, c_min = MAX + 1;
bool Judge_Color(int v, int col) { // 判断v是否可以用col涂色
  for (int i = 1; i <= V; i++)
    if (G[i][v] == 1 && color[i] == col) return false;
  return true;
}
void Solve(int v, int num_color) {
  if (num_color >= c_min) return;  //剪枝
  if (v > V) { // 涂色完毕
    c_min = min(c_min, num_color);
    return;
  }
  for (int i = 1; i <= num_color; i++) {
    if (Judge_Color(v, i)) { // 如果可以用这种颜色涂色
      color[v] = i;
      Solve(v + 1, num_color);
      color[v] = 0;  //回溯
    }
  }
  // num_color种颜色不够用了
  color[v] = num_color + 1; // 新增一种颜色
  Solve(v + 1, num_color + 1);
  color[v] = 0; // 回溯
}
int main() {
  cin >> V >> E;
  memset(G, 0, sizeof(G));
  memset(color, 0, sizeof(color));
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }
  Solve(1, 1);
  cout << "颜色最少使用种数为" << c_min << endl;
  return 0;
}
