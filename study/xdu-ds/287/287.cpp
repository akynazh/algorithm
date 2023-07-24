#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[1000][1000];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    int tag = 0;
    for (int i = 0; i < n; i++) {
        int min = mat[i][0], max = mat[i][0], col = 0, flag = 1;
        for (int j = 1; j < m; j++) {
            if (mat[i][j] < min) {
                min = mat[i][j]; col = j;
            }
            if (mat[i][j] == min) flag = 0;
        }
        if (!flag) continue;
        max = min; flag = 1;
        for (int j = 0; j < n; j++) 
            if (j != i && mat[j][col] >= max) flag = 0;
        if (flag) {
            printf("%d %d %d\n", i+1, col+1, mat[i][col]);
            tag = 1;
        }
    }
    if (!tag) printf("NO");
    return 0;
}