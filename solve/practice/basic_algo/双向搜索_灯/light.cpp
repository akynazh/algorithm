#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, ans = 0x7fffffff;
map<LL, int> f;
long long a[40];

int main() {
    cin >> n >> m;
    // 预处理 001 010 100 二进制位保存状态 自己到自己默认为1到别人默认为0
    a[0] = 1;
    for (int i = 1; i < n; i++) a[i] = a[i-1] * 2;
    // 建图
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        // 题目默认顶点从1开始 这里让顶点从0开始方便后续操作
        u--; v--; // 左移的是u(v)-1位
        // u和v有边则对应二进制位为1
        a[u] |= ((LL)1 << v);
        a[v] |= ((LL)1 << u);
    }
    // 对前一半进行搜索
    // 000 ~ 111 所有情况 如011表示这次只点亮第1和第2盏灯
    for (int i = 0; i < (1 << (n / 2)); i++) {
        LL  t = 0; // 状态标记
        int cnt = 0; // 点灯次数
        for (int j = 0; j < n / 2; j++) { // j为前一半状态a下标
        // 只要不为0则表示要点灯 
        // 101>>0==101 (&1==1) 第一盏灯要点，与t进行异或
        // 101>>1==10  (&1==0) 第二盏灯不点
        // 10 >>1==1   (&1==1) 第三盏灯要点，与t进行异或
            if ((i >> j) & 1) { 
                t ^= a[j];
                cnt++;
            }
        }
        if (!f.count(t)) f[t] = cnt;
        else f[t] = min(f[t], cnt);
    }
    // 对后一半进行搜索
    for (int i = 0; i < (1 << (n - n/2)); i++) {
        LL t = 0;
        int cnt = 0;
        for (int j = 0; j < (n - n/2); j++) {
            if ((i >> j) & 1) {
                t ^= a[n/2 + j];
                cnt++;
            }
        }
        // 若发现互补的路径则双向搜索成功，找到一条完成任务的通道
        // 如10010 ^ 11111 == 01101
        if (f.count( (((LL)1 << n) - 1) ^ t) )
            ans = min(ans, f[(((LL)1 << n) - 1) ^ t] + cnt);
    }
    cout << ans;
    return 0;
}