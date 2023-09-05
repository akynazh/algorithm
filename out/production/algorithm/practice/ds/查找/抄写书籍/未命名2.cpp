#include <iostream>
#include <cstring>
#define MAXN 510
int a[MAXN];
int m, k;

bool canSolve(long long ans)
{
    int heapCount = 1;  //当前堆数目
    long long pageCount = 0;  //当前堆页数
    for(int i = m - 1; i >= 0; i--) {  //从后向前判断每一本书
        if (a[i] + pageCount > ans) {
            heapCount++;
            pageCount = a[i];
        }else {
            pageCount += a[i];
        }
    }
    return (heapCount <= k);  //<k表明书少，不能尽量放一堆上，不然不能人守一本。
}

void print(long long ans)
{
    int heapCount = 1;
    long long pageCount = 0;
    bool divider[MAXN];
    memset(divider, true, sizeof(divider));
    for (int i = m - 1; i >= 0; i--) {
        if (k - heapCount == i + 1) {   //剩下的书数等于剩余未分配的抄写员的数目，只能人人分配一本。
            break;
        }
        if (a[i] + pageCount > ans) {
            heapCount++;
            pageCount = a[i];
        }
        else {
            divider[i] = false;
            pageCount += a[i];
        }
    }
    for (int i = 0; i < m - 1; i++){
        printf("%d ", a[i]);
        if (divider[i]) { printf("/ "); }
    }
    printf("%d\n", a[m - 1]);
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d%d", &m, &k);
        memset(a, 0, sizeof(a));
        long long l = 0, r = 0, mid = 0;
        for(int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
            r += a[i];
            if (l < a[i]) { l = a[i]; }
        }
        while(l <= r) {
            mid = (l + r) >> 1;
            canSolve(mid) ? (r = mid - 1) : (l = mid + 1);
        }
        print(l);
    }
    return 0;
}
