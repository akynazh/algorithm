// 埃及分数问题，用单位分数的和表示有理数，加数中不允许有相同的，加数少最好，加数等多时最小的分数越大越好
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int max_depth = 1000;
int a, b, maxd;
int ans[max_depth], v[max_depth]; // 结果集及其比较集，存单位分数分母

// 满足1/c <= a/b 的最小c，即1/c最大
int get_first(int a, int b) {
    int k;
    for (int i = 2; i < b; i++) {
        if ((double)1 / (double)i > (double)a / (double)b) return k;
        k = i;
    }
}
// 如果当前解v比目前最优解ans更优，则更新ans
bool better(int d) {
    for (int i = d; i >= 0; i--) if (v[i] != ans[i]) { // 从下往上搜，便于比较层数和最小分数较大者
        return ans[i] == -1 || v[i] < ans[i];
        // ans层数更小或者在等层数的条件下ans最小的分数更大
    }
    return false;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
// 当前深度为d，父母不小于from，分数之和恰为 aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
    if (d == maxd) { // 一旦到达最大深度限制就停止递归
        if (bb % aa) return false; // 不是单位分数
        v[d] = bb / aa; 
        if (better(d)) memcpy(ans, v, sizeof(LL)*(d+1));
        return true;
    }
    bool ok = false;
    int t = get_first(aa, bb);
    from = from > t ? from : t; // 枚举起点
    for (int i = from; ; i++) {
        // 即1 / i * (maxd+1-d) <= aa / bb 剪枝，若剩余所有层数都用这个数都小于目标值则直接取消递归
        if (bb * (maxd+1-d) <= i * aa) break;
        v[d] = i;
        // 进行 aa/bb - 1/i 运算
        LL b2 = bb * i;
        LL a2 = aa * i - bb;
        LL g = gcd(a2, b2); // 方便约分
        if (dfs(d+1, i+1, a2/g, b2/g)) ok = true;
    }
    return ok;
}
int main() {
    scanf("%d%d", &a, &b); // a/b
    printf("%d", get_first(a, b));
    int ok = 0;
    for (maxd = 1; ; maxd++) { // 迭代加深搜索
        memset(ans, -1, sizeof(ans));
        if (dfs(0, get_first(a, b), a, b)) {
            ok = 1;
            break;
        }
    }
    if (ok) for (int i = 1; i <= maxd; i++) printf("1/%d+", ans[i]);
    else printf("fail");
    return 0;
}