#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char s[110];
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0, j = n-1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}