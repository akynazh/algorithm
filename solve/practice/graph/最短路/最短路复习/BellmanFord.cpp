// �����������㷨 O(VE)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXE = 100; 
const int INF = 0x3f3f3f3f;
// �����޻�ͼ DAG
struct Edge {
	int from, to, cost;
};
int V, E; 				// �������ͱ��� 
int d[MAXN]; 			// ��ĳ��s��������������������·�����ȣ���ʼֵΪINF 
Edge edge[MAXE];		// �߼�  

// ��ʼ��ͼ 
void init() {
	cin >> V >> E;
	int from, to, cost;
	for (int i = 0 ; i < E; i++) 
		cin >> edge[i].from >> edge[i].to >> edge[i].cost;
}
// �����������㷨������·����Ա�չ����ֻ�轨���߼������轨ͼ������� 
void Bellman_Ford(int s)
{
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	int c = 0; 
	while (1) {
		int flag = 0;
		// DAG�����ٸ���E��
		for (int i = 0; i < E; i++) {
			Edge e = edge[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				flag = 1;
			}
		}
		// ���û���ָ������˳�
		if (!flag) break;
		c++;
		if (c >= V) {
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
	Bellman_Ford(0); 
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




