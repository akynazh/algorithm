#include <bits/stdc++.h>
using namespace std;
int n, m;
int num1 = 0, num2 = 0, num = 0;
int v1[10000], b1[100][100];
int v2[10000], b2[100][100];
int v[10000], b[100][100];
void get_input() {
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) {
        scanf("%d", &b1[i][j]);
        if (b1[i][j]) num1++;
    }
    for (int i = 0; i < num1; i++) scanf("%d", &v1[i]);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            scanf("%d", &b2[i][j]);
            if (b2[i][j]) num2++;
        }
    for (int i = 0; i < num2; i++) scanf("%d", &v2[i]);
}
void solve() {
    int idx1 = 0, idx2 = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ssum = 0;
            if (b1[i][j] || b2[i][j]) {
                if (b1[i][j]) {ssum += v1[idx1]; idx1++;}
                if (b2[i][j]) {ssum += v2[idx2]; idx2++;}
                if (ssum) {num++; b[i][j] = 1; v[idx] = ssum; idx++;}
            }
        }
    }
}
void print_ans() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%d ", b[i][j]);
        printf("\n");
    }
    for (int i = 0; i < num; i++) printf("%d ", v[i]);
}
int main() {
    memset(b1, 0, sizeof(b1));
    memset(b2, 0, sizeof(b2));
    memset(b, 0, sizeof(b));
    cin >> n >> m;
    get_input();
    solve();
    print_ans();
    return 0;
}