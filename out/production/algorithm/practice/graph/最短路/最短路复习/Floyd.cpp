// ���������㷨 O(V^3)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
// �����޻�ͼ DAG
int V, E; 				// �������ͱ���
int graph[MAXN][MAXN];  // DAG�ڽӾ��󣬳�ʼֵΪINF�����ɴ�ΪINF������Ϊcostֵ
int d[MAXN][MAXN];		// ���������������������������·�����ȣ���ʼֵΪINF
 
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
// ���������㷨������·
void Floyd()
{
	// ��ʼ������d 
	memset(d, 0x3f, sizeof(d));
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			d[i][j] = graph[i][j];
	for(int k = 0; k < V; k++){//�Զ���kΪ��ת
		for(int i = 0; i < V; i++){//�Ӷ���i������j
			for(int j = 0; j < V; j++){
				if (d[i][j] > d[i][k] + d[k][j]) 
					d[i][j] = d[i][k] + d[k][j];
			}
		} 
	} 
}
void print_ans() {
	for (int i = 0; i < V; i++) {
		cout << endl;
		for (int j = 0; j < V; j++) {
			if (d[i][j] > 100) printf("%3d ", -1);
			// ����ĳ��ֵ��Ϊ���ɴ� 
			else printf("%3d ", d[i][j]);
		}
	}
}
int main() {
	init();
	Floyd();
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

-1  3  2  5  4 11
-1 -1 -1 -1  1 11
-1 -1 -1  4  5  9
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 10
-1 -1 -1 -1 -1 -1

�ɽ��������DAG 
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

 -1   3   2 -89   4  11
 -1  -1  -1 -89   1  11
 -1  -1  -1 -91   5   9
 -1  -1  -1  -1  -1  -1
 -1  -1  -1 -90  -1  10
 -1  -1  -1 -100  -1  -1
*/


