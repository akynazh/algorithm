#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;

char mmap[MAXN][MAXN];
bool vis[3][MAXN];
int n, ssum = 0;

void solve(int cur) {
    if (cur == n)
        ssum++;
    else {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && !vis[1][cur - i + n] && !vis[2][cur + i]) {
                vis[0][i] = vis[1][cur - i + n] = vis[2][cur + i] = true;
                solve(cur + 1);
                vis[0][i] = vis[1][cur - i + n] = vis[2][cur + i] = false;
                flag = true;
            }
        }
        if (!flag) {
            solve(cur + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mmap[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mmap[i][j] == '*') {
                vis[0][j] = vis[1][i - j + n] = vis[2][i + j] = true;
            }
        }
    }
    solve(0);
    cout << ssum;
    return 0;
}
