#include <bits/stdc++.h>
using namespace std;
int n, d;
vector<int> v;
int main() {
    v.resize(1010);
    for (;;) {
        scanf("%d", &n);
        if (n == 0) break;
        v.clear();
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        scanf("%d", &d);
        int above = (1 << (d-1)) - 1;
        int num = n - above;
        if (num <= 0) printf("EMPTY\n");
        else {
            int idx = above + 1;
            int maxnum = idx + (1 << (d-1)) - 1;
            while (idx <= n && idx <= maxnum) {
                printf("%d ", v[idx]);
                idx++;
            }
            printf("\n");
        }
    }
    return 0;
}