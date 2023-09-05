// �����������㷨���Ż� O(VE) SPFA_���ȶ��� 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
// �����޻�ͼ DAG
int V, E; 				// �������ͱ���
int graph[MAXN][MAXN];  // DAG�ڽӾ��󣬳�ʼֵΪINF�����ɴ�ΪINF������Ϊcostֵ 
int d[MAXN]; 			// ��ĳ��s��������������������·�����ȣ���ʼֵΪINF 
int vis[MAXN]; 		 // ����Ƿ������ 
int push_count[MAXN]; // �����Ӵ����������ڵ���V����֤�����ڸ��� 
priority_queue<int, vector<int>, greater<int> > que; // greater<T> ��С����ȡ�� 

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
// SPFA�㷨������· 
void SPFA(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	memset(push_count, 0, sizeof(push_count));
	d[s] = 0;
	que.push(s);
	vis[s] = 1;
	push_count[s]++;
	while (!que.empty()) {
		int flag = 0; // �����ж� 
		int v = que.top(); que.pop(); vis[v] = 0;
		for (int i = 0; i < V; i++) {
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
			cout << "�и���" << endl;
			break;
		} 
	} 
}
void print_ans() {
	cout << endl;
	for (int i = 0; i < V; i++) cout << d[i] << " ";
}

int main() {
	init();
	SPFA(0); 
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

�ɽ������������ 
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

0 3 2 -89 4 11

���ж��Ƿ񺬸��� 
6 7
0 1 2
1 2 2
2 3 3
2 4 4
3 4 5
4 5 -7
5 3 1

�и���

0 2 4 -2 4 -3
*/





