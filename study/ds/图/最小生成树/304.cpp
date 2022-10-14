#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
struct Edge {
    int from, to, w;
    Edge(int a, int b, int c) {from = a; to = b; w = c;}
};
int n, m;
vector<Edge> edges;
int parent[maxn+10];
bool cmp (Edge e1, Edge e2) {return e1.w <= e2.w;}
int pfind(int x) { // 寻找祖先
    if (parent[x] == x) return x;
    return parent[x] = pfind(parent[x]);
}
void merge(int x, int y) {parent[pfind(y)] = pfind(x);} // 合并为同一祖先
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    int from, to, w, count = 0;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> w;
        edges.push_back(Edge(from, to, w));
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < m; i++) {
        from = edges[i].from; to = edges[i].to; w = edges[i].w;
        if (pfind(from) != pfind(to)) {
            if (from > to) printf("%d %d %d\n", to, from, w);
            else printf("%d %d %d\n", from, to, w);
            merge(from, to);
            count++;
            if (count == n-1) break;
        } 
    }
    return 0;
}