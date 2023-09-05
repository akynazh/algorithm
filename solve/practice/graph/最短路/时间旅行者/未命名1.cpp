// �����������㷨���Ż� O(VE) SPFA_���ȶ��� 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;
// �����޻�ͼ DAG
int V, E; 				// �������ͱ���
int graph[MAXN][MAXN];  // DAG�ڽӾ��󣬳�ʼֵΪINF�����ɴ�ΪINF������Ϊcostֵ 
int d[MAXN]; 			// ��ĳ��s��������������������·�����ȣ���ʼֵΪINF 
int vis[MAXN]; 		 // ����Ƿ������ 
int push_count[MAXN]; // �����Ӵ����������ڵ���V����֤�����ڸ��� 
priority_queue<int, vector<int>, greater<int> > que; // greater<T> ��С����ȡ�� 
int flag = 0;
// SPFA�㷨������· 
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

