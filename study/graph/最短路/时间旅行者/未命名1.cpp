// 贝尔曼福德算法的优化 O(VE) SPFA_优先队列 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;
// 有向无环图 DAG
int V, E; 				// 顶点数和边数
int graph[MAXN][MAXN];  // DAG邻接矩阵，初始值为INF，不可达为INF，否则为cost值 
int d[MAXN]; 			// 从某点s出发到其它任意结点的最短路径长度，初始值为INF 
int vis[MAXN]; 		 // 结点是否已入队 
int push_count[MAXN]; // 结点入队次数，若大于等于V，则证明存在负环 
priority_queue<int, vector<int>, greater<int> > que; // greater<T> 从小到大取出 
int flag = 0;
// SPFA算法求解最短路 
void SPFA(int s) {
	while (!que.empty()) que.pop();
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	memset(push_count, 0, sizeof(push_count));
	d[s] = 0;
	que.push(s);
	vis[s] = 1;
	push_count[s]++;
	while (!que.empty()) {
		int v = que.top(); que.pop(); vis[v] = 0;
		for (int i = 1; i <= V; i++) {
			if (d[v] + graph[v][i] < d[i]) {
				d[i] = d[v] + graph[v][i];
				if (!vis[i]) {
					que.push(i);
					vis[i] = 1;
					push_count[i]++;
					if (push_count[i] >= V) {
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag) {
			break;
		}
	} 
}

int main() {
		
	while (cin >> V >> E) {
		memset(graph, 0x3f, sizeof(graph));
		int from, to, cost;
		flag = 0;
		for (int i = 0 ; i < E; i++) {
			cin >> from >> to >> cost;
			graph[from][to] = cost;
		}
		SPFA(1);
		if (d[V] < 0 || flag == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
/*
5 5
1 2 3
2 3 1
3 2 -2
1 4 5
3 5 10

3 2
1 2 4
2 3 -5

4 4
1 2 3
2 3 1
3 2 -2
1 4 5
*/

