#include <bits/stdc++.h>
using namespace std;
int n, L, cnt; // 由前L个字母组成的第n个困难的串 cnt等于n时表示寻找结束 
const int maxlen = 80 + 10; // 最长串长度
int S[maxlen];
int find_string(int cur) { // cur表示串的长度-1
    if (n == cnt++) { // 当cnt等于n时寻找结束，每尝试1种可能都必须使cnt加1
        int count = 0, group = 0;
        for (int i = 0; i < cur; i++) {
            if (count && count % 4 == 0) {
                group++;
                if (group % 16 == 0) printf("\n");
                else printf(" ");
            }
            printf("%c", 'A' + S[i]);
            count++;
        }
        printf("\n%d\n", cur);
        return 0; // 第一个达到n的串就是结果，返回0递归结束
    }
    for (int i = 0; i < L; i++) { // 前L个字母
        S[cur] = i;
        int ok = 1;
        // 尝试长度为j*2的后缀（则长度为奇数的后缀不会纳入计算咯）
        for (int j = 1; j * 2 <= cur + 1; j++) {
            int equal = 1;
            for (int k = 0; k < j; k++) {
                // 后缀的前后两半对应位置字符，如果有一对不相等则证明该后缀是困难的串
                if (S[cur-k] != S[cur-k-j]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) {
                ok = 0;
                break;
            }
        }
        if (ok) if (!find_string(cur+1)) return 0;// 得到结果递归结束
    }
    return 1;
}
int main() {
    for (;;) {
        scanf("%d%d", &n, &L);
        if (n == 0 && L == 0) break;
        cnt = 0;
        find_string(0);
    }
    return 0;
}