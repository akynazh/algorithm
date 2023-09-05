#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int G[MAX][MAX];
int color[MAX];
int V, E, num_color, ccount = 0;
bool Judge_Color(int v, int col) { // ��v����col����Ϳɫ
  for (int i = 1; i <= V; i++)
    if (G[i][v] == 1 && color[i] == col) return false;
  return true;
}
void Solve(int v) {
  if (v > V) { // Ϳɫ���
    ccount++;
    for (int i = 1; i <= V; i++) cout << color[i] << " ";
    cout << endl;
    return;
  }
  for (int i = 1; i <= num_color; i++) {
    if (Judge_Color(v, i)) { // �������Ϳɫ�����Ϳɫ
      color[v] = i;
      Solve(v + 1);
      color[v] = 0; // ����
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
  Solve(1); // �ӵ�һ����㿪ʼͿɫ
  cout << "���������" << ccount << "��" << endl;
  return 0;
}
