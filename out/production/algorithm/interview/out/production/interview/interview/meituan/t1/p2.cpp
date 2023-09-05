#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000, MAX_COL = 2000;
int N, K, arr[MAX_N], vis[MAX_COL];

int dfs(int idx, int c, int len) {
    if (idx == N || c > K) return len;
    if (!vis[arr[idx]]) {
        if (c + 1 > K) return len;
        vis[arr[idx]] = 1;
        c++;
    }
    return dfs(++idx, c, ++len);
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        memset(&vis, 0, sizeof(vis));
        int res = dfs(i, 0, 0);
        if (res > ans) ans = res;
    }
    cout << ans;
    return 0;
}
