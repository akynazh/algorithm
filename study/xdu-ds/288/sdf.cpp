#include <bits/stdc++.h>
using namespace std;
int main() {
    char str[10000];
    int n, next[10000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    next[0] = -1;
    int a = 0, b = -1;
    while (a < n && b < n) {
        if (b == -1 || str[a] == str[b]) {
            a++; b++;
            next[a] = b;
        } else b = next[b];
    }
    for (int i = 0; i < n; i++) printf("%d ", next[i]);
    return 0;
}