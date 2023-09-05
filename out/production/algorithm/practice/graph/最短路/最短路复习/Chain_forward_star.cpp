#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
struct Edge {
	int to; // �ߵ��յ� 
	int next; // ��ñ�ͬ������һ���ߵı�� 
	int w; // �ߵ�Ȩֵ 
};
Edge edge[MAXN]; // ���бߵļ���
int head[MAXN]; // �������ĵ�һ���ߵı�ţ���ʼ��Ϊ-1 
int V, E;
// ����ͼ 
void build() {
	int from, to, w, cnt = 0;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> w;
		edge[cnt].to = to;
		edge[cnt].w = w;
		edge[cnt].next = head[from]; // ��˿ɽ�head��ʼ��Ϊ-1����nextΪ-1ʱ�����Ըõ�Ϊ���ı߷��ʽ��� 
		head[from] = cnt++;
	}
}
// ��������ͼ 
void traverse() {
	for (int i = 0; i < V; i++) {
		for (int j = head[i]; j != -1; j = edge[j].next) {
			cout << " from " << i << " to " << edge[j].to << " weight: " << edge[j].w << endl;
		}
	}
}
// ����ĳ�������ڽӵ� 
void traverse_v(int v) {
	for (int i = head[v]; i != -1; i = edge[i].next) {
		cout << " from " << v << " to " << edge[i].to << " weight: " << edge[i].w << endl; 
	}
}
int main() {
	memset(head, -1, sizeof(head));
	cin >> V >> E;
	build(); 
	traverse();
	cout << endl;
	traverse_v(1);
	return 0;
} 
/*
5 7
1 2 1
2 3 2
3 4 3
1 3 4
4 1 5
1 5 6
4 5 7
*/
