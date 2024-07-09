#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;

int n;
string s;
int mmap[MAX_N + 1][MAX_N + 1];
int vis[MAX_N + 1];

int solve(int k) {
    vis[k] = 1;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (i != k && !vis[i]) {
            if (mmap[k][i] && s[i] == s[k]) {
                s[i] = s[i] == 'R' ? 'W' : 'R';
                c++;
            }
            c += solve(i);
        }
    }
    return c;
}

int main() {
    memset(&mmap, 0, sizeof(mmap));
    memset(&vis, 0, sizeof(vis));
    cin >> n >> s;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        mmap[a][b] = mmap[b][a] = 1;
    }
    int mmin = MAX_N;
    for (int i = 1; i <= n; i++) {
        int res = solve(i);
        if (res < mmin) mmin = res;
    }
    cout << mmin;
    return 0;
}
