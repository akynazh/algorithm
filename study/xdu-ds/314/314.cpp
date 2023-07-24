#include <bits/stdc++.h>
using namespace std;
int m, n, ans;
void solve(int v) {
    if (2 * v <= n) {
        ans++;
        solve(2 * v);
    }
    if (2 * v + 1 <= n) {
        ans++;
        solve(2 * v + 1);
    }
}
int main() {
    for(;;) {
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0) break;
        ans = 1;
        solve(m);
        printf("%d\n", ans);
    }
    return 0;
}