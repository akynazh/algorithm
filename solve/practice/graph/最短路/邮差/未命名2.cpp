#include<cstdio>
#include<queue>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
//多对一：反向建图 
struct edge{
	int to, w;
	edge* next;
}; 
struct fnode{
	edge *start;
};
int n, m;
fnode LG1[1001];
fnode LG2[1001];//反图 
long long least_t = 0;
long long length[1001];
bool visited[1001];
void shortest(int s, int flag){
	memset(length, inf, sizeof(length));
	memset(visited, false, sizeof(visited));
	length[s] = 0;
	for(int i = 1; i <= n; i++){
		long long minl = inf;
		int k;
		for(int j = 1; j <= n; j++){
			if(visited[j] != true && length[j] < minl){
				minl = length[j];
				k = j;
			}
		}
		visited[k] = true;
		edge *e = new edge;
		if(flag == 1)	e = LG1[k].start;
		else if(flag == 2) e = LG2[k].start;
		while(e != NULL){
			int u = e->to;
			if(visited[u] != true && length[u] > length[k] + e->w){
				length[u] = length[k] + e->w;
			}
			e = e->next;
		}
	}
	return;
}

//typedef pair<int, int> P;
//void shortest_update(int s){
//	memset(length, inf, sizeof(length));
//	length[s] = 0;
//	priority_queue<P, vector<P>, greater<P> > Q;
//	P p_s(0, s);
//	Q.push(p_s);
//	while(!Q.empty()){
//		P p = Q.top();
//		Q.pop();
//		if(p.first > length[p.second])	continue;
//		edge *e = new edge;
//		e = LG[p.second].start;
//		while(e != NULL){
//			int u = e->to;
//			if(length[u] > e->w + p.first){
//				length[u] = e->w + p.first;
//				P p_t(length[u], u);
//				Q.push(p_t);
//			}
//			e = e->next;
//		}
//	}
//	return;
//}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		
		edge *e1 = new edge;
		e1->to = b;
		e1->w = c;
		e1->next = LG1[a].start;
		LG1[a].start = e1;
		
		edge *e2 = new edge;
		e2->to = a;
		e2->w = c;
		e2->next = LG2[b].start;
		LG2[b].start = e2; 
	}
	shortest(1, 1);
	//shortest_update(1);
	for(int i = 2; i <= n; i++)	least_t += length[i];
//	for(int i = 2; i <= n; i++){
//		shortest(i);
//		//shortest_update(i);
//		least_t += length[1];
//	}
	shortest(1, 2);
	for(int i = 2; i <= n; i++)	least_t += length[i];
	printf("%lld", least_t);
	return 0;
}
