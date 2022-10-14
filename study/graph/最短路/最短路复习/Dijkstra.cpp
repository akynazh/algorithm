// �Ͻ�˹�����㷨 O(V^2)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
// �����޻�ͼ DAG
int V, E; 				// �������ͱ���
int graph[MAXN][MAXN];  // DAG�ڽӾ��󣬳�ʼֵΪINF�����ɴ�ΪINF������Ϊcostֵ 
int d[MAXN]; 			// ��ĳ��s��������������������·�����ȣ���ʼֵΪINF 
int visited[MAXN]; 		// ĳ���Ƿ���ʹ������ʹ���Ϊ1����Ϊ0

// ��ʼ��ͼ 
void init() {
	memset(graph, 0x3f, sizeof(graph));
	cin >> V >> E;
	int from, to, cost;
	for (int i = 0 ; i < E; i++) {
		cin >> from >> to >> cost;
		graph[from][to] = cost;
	}
}
// �Ͻ�˹�����㷨������·����Ե�չ�� 
void Dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(visited, 0, sizeof(visited));
	visited[s] = 1;
	for(int i = 0; i < V; i++) d[i] = graph[s][i];
	d[s] = 0;
	int k, min_cost;
	// �޸���ʱ������n-1(���������)�� 
	for(int i = 0; i < V - 1; i++){
		min_cost = INF;
		// Ѱ����δ�����ʵ���Ȩֵ��С��·������Ҫ�Ż��ĵط� 
		for(int j = 0; j < V; j++){
			if(!visited[j] && d[j] < min_cost){
				k = j;
				min_cost = d[j];
			}
		}
		visited[k] = 1;
		// �����ҵ��Ľ��������·��
		for(int j = 0; j < V; j++){
			if(!visited[j] && min_cost + graph[k][j] < d[j]){
				d[j] = min_cost + graph[k][j];
			}
		}
	}
} 
void print_ans() {
	cout << endl;
	for (int i = 0; i < V; i++) cout << d[i] << " ";
}

int main() {
	init();
	Dijkstra(0);
	print_ans();
	return 0;
} 
/*
6 8
0 1 3
0 2 2
0 3 5
1 4 1
2 4 5
2 5 9
2 3 4
4 5 10

0 3 2 5 4 11

���ɽ������������ 
6 9
0 1 3
0 2 2
0 3 5
1 4 1
2 4 5
2 5 9
2 3 4
4 5 10
5 3 -100

0 3 2 5 4 11
*/


