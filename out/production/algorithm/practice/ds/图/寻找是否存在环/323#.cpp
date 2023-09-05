#include <bits/stdc++.h> // 使用于有向图中判断是否有环的算法：拓扑序的思想
using namespace std;
const int maxn = 100 + 10;
int mat[maxn][maxn], in_num[maxn];
int n, num;
vector<int> ans;
int topo() {
    stack<int> st;
    int ncount = 0;
    for (int i = 0; i < num; i++) if (!in_num[i]) st.push(i); // 找到第一个入度为0的结点
    while(!st.empty()) {
        int k = st.top(); st.pop(); ncount++;
        for (int i = 0; i < num; i++) {
            if (mat[k][i]) 
                if (--in_num[i] == 0) st.push(i); // 如果减去1后入度为0则属于拓扑序结点，进栈
        }
    }
    return ncount;
}
int main() {
    scanf("%d", &n);
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        memset(in_num, 0, sizeof(in_num));
        for (int j = 0; j < num; j++)
            for (int k = 0; k < num; k++) {
                scanf("%d", &mat[j][k]);
                if (mat[j][k]) in_num[k]++; // 计算入度
            }
        int ncount = topo(); // 如果拓扑序中进栈的结点小于总结点数则证明含有环
        if (ncount < num) ans.push_back(1);
        else ans.push_back(0);
    }
    for (int i = 0; i < n; i++) printf("%d", ans[i]);
    return 0;
}