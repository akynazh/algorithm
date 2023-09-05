#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int n, m[maxn][maxn], in_num[maxn];
int ve[maxn], vl[maxn]; // 每个点（状态）的最早和最晚发生时间
stack<int> st, r_st; // 拓扑正序和逆序
int topo() { // 通过正拓扑序判断是否有环，并导出逆拓扑序和计算ve0
    int num = 0;
    st.push(0);
    while (!st.empty()) {
        int k = st.top(); st.pop(); r_st.push(k); num++;
        for (int i = 0; i < n; i++) if (m[k][i]) {
            if (--in_num[i] == 0) st.push(i);
            if (ve[k] + m[k][i] > ve[i]) ve[i] = ve[k] + m[k][i];
        }
    }
    return num;
}
int criticalPath() {
    if (topo() < n) return 0; // 含有环，构造失败
    for (int i = 0; i < n; i++) vl[i] = ve[n-1]; // 初始化
    while (!r_st.empty()) { // 由拓扑逆序计算vl
        int k = r_st.top(); r_st.pop();
        for (int i = 0; i < n; i++) if (m[i][k]) {
            if (vl[k] - m[i][k] < vl[i]) vl[i] = vl[k] - m[i][k];
        }
    }
    int next = 0, ans = 0; // 关键路径的下一个点 关键路径长度
    while (next != n-1) { // 计算关键路径长度
        for (int i = 0; i < n; i++) if (m[next][i]) {
            if (ve[next] == vl[i] - m[next][i]) {
                // 活动的最早开始时间等于最晚开始时间
                ans += m[next][i];
                next = i;
                break;
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    memset(in_num, 0, sizeof(in_num));
    memset(ve, 0, sizeof(ve));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
            if (m[i][j]) in_num[j]++;
        }
    int ans = criticalPath();
    if (ans) printf("%d", ans);
    else printf("NO");
    return 0;
}