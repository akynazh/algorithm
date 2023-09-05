#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;
int G[MAX][MAX];
int room[MAX][MAX]; // 保存教室i中第j个学生的id
int c_stu, c_relation, min_room = MAX + 1, count_room;
void solve(int x, int count_room) {
  if (count_room >= min_room) return; // 剪枝
  if (x > c_stu) { // 学生分配完毕
    min_room = min(min_room, count_room);
    return;
  }
  for (int i = 1; i <= count_room; i++) {
    int flag = true, j = 0;
    while (room[i][j]) { //查找学生教室中是否有认识的人
      if (G[x][room[i][j]]) {
        flag = false;
        break;
      }
      j++;
    }
    if (flag) { // 教室里没有认识的人
      room[i][j] = x;
      solve(x + 1, count_room); // 继续用现有教室分配下一个学生
      room[i][j] = 0;
    }
  }
  // 教室不够 新增一个教室并把学生放进教室
  room[count_room + 1][0] = x;
  solve(x + 1, count_room + 1);
  room[count_room + 1][0] = 0;
}

int main() {
  memset(G, 0, sizeof(G));
  memset(room, 0, sizeof(room));
  cin >> c_stu >> c_relation;
  for (int i = 0; i < c_relation; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }
  solve(1, 1); // 最开始用一个教室分配学生
  cout << min_room << endl;
  return 0;
}
