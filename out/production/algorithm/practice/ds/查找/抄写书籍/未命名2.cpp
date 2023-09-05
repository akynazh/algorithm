#include <iostream>
#include <cstring>
#define MAXN 510
int a[MAXN];
int m, k;

bool canSolve(long long ans)
{
    int heapCount = 1;  //��ǰ����Ŀ
    long long pageCount = 0;  //��ǰ��ҳ��
    for(int i = m - 1; i >= 0; i--) {  //�Ӻ���ǰ�ж�ÿһ����
        if (a[i] + pageCount > ans) {
            heapCount++;
            pageCount = a[i];
        }else {
            pageCount += a[i];
        }
    }
    return (heapCount <= k);  //<k�������٣����ܾ�����һ���ϣ���Ȼ��������һ����
}

void print(long long ans)
{
    int heapCount = 1;
    long long pageCount = 0;
    bool divider[MAXN];
    memset(divider, true, sizeof(divider));
    for (int i = m - 1; i >= 0; i--) {
        if (k - heapCount == i + 1) {   //ʣ�µ���������ʣ��δ����ĳ�дԱ����Ŀ��ֻ�����˷���һ����
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
