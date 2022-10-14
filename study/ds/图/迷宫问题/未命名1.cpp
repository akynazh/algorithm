#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;
int m, n, x1, y1, x2, y2, flag = 0;
struct Pos {
	int tag, dir;
};
Pos maze[100][100];
struct Dir {
	int x, y;
};
Dir go[5];
int vis[100][100];

void init() {
	cin >> m >> n >> x1 >> y1 >> x2 >> y2;
	memset(vis, 0, sizeof(vis));
	vis[x1][y1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &maze[i][j].tag);
			maze[i][j].dir = 1;
		}
	}
	go[1].x = 0; go[1].y = 1;
	go[2].x = 1; go[2].y = 0;
	go[3].x = 0; go[3].y = -1;
	go[4].x = -1; go[4].y = 0;
}
void solve(int x, int y) {
	if (flag) return;
	int dir1 = maze[x][y].dir; 
	for (int i = dir1; i <= 4; i++) {
		if (flag) break;
		int a = x + go[i].x, b = y + go[i].y;
		maze[x][y].dir = i;
		if (a >0 && b > 0 && a <= m && b <= n && maze[a][b].tag != 1 && !vis[a][b]) {
			vis[a][b] = 1;
			if (a == x2 && b == y2) flag = 1;
			solve(a, b);
		}
	}
}
void print_ans(int x, int y) {
	if (x == x2 && y == y2) printf("(%d,%d,%d)", x, y, maze[x][y].dir);
	else {
		printf("(%d,%d,%d),", x, y, maze[x][y].dir);
		int a = x + go[maze[x][y].dir].x, b = y + go[maze[x][y].dir].y;
		print_ans(a, b);
	}
}
int main() {
	init();
	solve(x1, y1);
	if (!flag) printf("no");
	else print_ans(x1, y1);
	return 0;	
}
