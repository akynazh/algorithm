#include <bits/stdc++.h>
using namespace std;
const int MAX_S = 1000;
int N, A, B, mmap[MAX_S + 1][MAX_S + 1], vis[MAX_S + 1][MAX_S + 1];

int get_ans(int lx, int ly, int rx, int ry) {
    int ans = 1;
    lx = lx < 1 ? 1 : lx;
    ly = ly < 1 ? 1 : ly;
    rx = rx > MAX_S ? MAX_S : rx;
    ry = ry > MAX_S ? MAX_S : ry;
    for (int i = lx; i <= rx; i++) {
        for (int j = ly; j <= ry; j++) {
                if (mmap[i][j] && !vis[i][j]) {
                    vis[i][j] = 1;
                    
                    cur_ans = get();
                    if (cur_ans > ans) ans = cur_ans;
                    vis[i][j] = 0;
                }
            }
        }
    }
    return ans;
}

int main() {
    int x, y, ans = -1;
    memset(&mmap, 0, sizeof(mmap));
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        mmap[x][y] = 1;
    }
    for (int i = 1; i <= MAX_S; i++) {
        for (int j = 1; j <= MAX_S; j++) {
            if (mmap[i][j]) {
                int lx = i - A, ly = j - B, rx = i + A, ry = j + B;
                int res = get_ans(lx, ly, rx, ry);
                if (res > ans) ans = res;
            }
        }
    }
    cout << ans;
    return 0;
}
