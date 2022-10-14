#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int t1[110], t2[110];
    for (int i = 0; i < a; i++) scanf("%d", &t1[i]);
    for (int i = 0; i < b; i++) scanf("%d", &t2[i]);
    int p1 = 0, p2 = 0;
    while (p1 < a && p2 < b) {
        if (t1[p1] == t2[p2]) {
            printf("%d ", t1[p1]);
            p1++; p2++;
        } else if (t1[p1] < t2[p2]) {
            printf("%d ", t1[p1]);
            p1++;
        } else {
            printf("%d ", t2[p2]);
            p2++;
        }
    }
    while (p1 < a) {
        printf("%d ", t1[p1]);
        p1++;
    }
    while (p2 < b) {
        printf("%d ", t2[p2]);
        p2++;
    }
    return 0;
}