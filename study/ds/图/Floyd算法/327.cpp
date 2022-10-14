#include <bits/stdc++.h>
using namespace std;
const int maxw = 10000;
int n;
int mat[1000][1000], path[1000][1000];
void Floyd() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (mat[i][j] < maxw) path[i][j] = j;
            else path[i][j] = -1;
        }
    for (int by = 0; by < n; by++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (mat[i][by] + mat[by][j] < mat[i][j]) {
                    mat[i][j] = mat[i][by] + mat[by][j];
                    path[i][j] = path[i][by];
                }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &mat[i][j]);
    Floyd();
    int from, to, k;
    for (;;) {
        scanf("%d%d", &from, &to);
        if (from == -1 && to == -1) break;
        k = path[from][to];
        if (k < 0) {
            printf("NO\n");
            continue;
        }
        printf("%d\n", mat[from][to]);
        printf("%d ", from);
        while (k != to) {
            printf("%d ", k);
            k = path[k][to];
        }
        printf("%d ", to);
        printf("\n");
    }
    return 0;
}