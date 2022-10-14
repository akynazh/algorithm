// �Ͻ�˹�����㷨�Ķ��Ż� O(ElogV) ������Ȩ�� 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
// �����޻�ͼ DAG
int V, E; 				// �������ͱ���
int graph[MAXN][MAXN];  // DAG�ڽӾ��󣬳�ʼֵΪINF�����ɴ�ΪINF������Ϊcostֵ 
int d[MAXN]; 			// ��ĳ��s��������������������·�����ȣ���ʼֵΪINF 
int visited[MAXN]; 		// ĳ���Ƿ���ʹ������ʹ���Ϊ1����Ϊ0

typedef pair<int, int> P; // first: ��̾��� second��ͨ���Ķ����� 
priority_queue<P, vector<P>, greater<P> > que; // greater<T> ��С����ȡ�� 

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
// �Ͻ�˹�����㷨���Ż�������·����Ե�չ��
void Dijkstra_optimise(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(visited, 0, sizeof(visited));
	// for(int i = 0; i < V; i++) d[i] = graph[s][i];
	// ��ʼmin_costΪ0����������һ����0 + graph[k][i]  == d[i] == graph[k][i]�������޷����¶��� 
	d[s] = 0;
	int k, min_cost;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		// ͨ�����Ż�ֱ�ӻ����Ŀ�� 
		min_cost = p.first;
		k = p.second;
		// ���Ѿ��и��̵�·���򲻸��� 
		if (min_cost > d[k]) continue;
		visited[k] = 1;
		for (int i = 0; i < V; i++) {
			if (!visited[i] && min_cost + graph[k][i] < d[i]) {
				d[i] = graph[k][i] + min_cost;
				que.push(P(d[i], i));
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
	Dijkstra_optimise(0); 
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


