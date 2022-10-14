// n*n棋盘放置n个皇后使得它们互不攻击 攻击范围为同行同列主副对角线
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, ans = 0;
int visited[3][maxn*2+10]; // 同列同主副对角线 访问记录
int a[maxn+10]; // 排列结果

void search(int c){
	if(c == n){ // 当c==n时摆放结束
		// 打印结果
		// for(int i = 0; i < n-1; i++)	printf("%d ", a[i]);
		// printf("%d\n", a[n-1]);
		ans++; // 排列结果数加一
	}else{
		for(int i = 0; i < n; i++){
			// 按行摆，再考虑同列同主副对角线是否有其他皇后
			// 行列之差标记主对角线 行列之和标记副对角线 
			if(!visited[0][i] && !visited[1][c-i+n] && !visited[2][c+i]){
				visited[0][i] = visited[1][c-i+n] = visited[2][c+i] = 1;
				a[c] = i;
				search(c+1); // 继续开摆下一行
				visited[0][i] = visited[1][c-i+n] = visited[2][c+i] = 0; // 回溯
			}
		}
	}
}
int main(){
	memset(visited, 0, sizeof(visited));
	cin >> n;
	search(0); // 从第0行开摆
	printf("%d", ans);
	return 0;
}
