#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, x;
vector<int> a(105);
int memo[105][105][2];

// 最多只能选择一个账号多发！！审题！！
// memo[x][y][true]
// memo[x][y][false]

int helper(int i, int x, bool extra) {
    if (x == 0) return 0;
    if (i >= n) return n + 1;
    if (memo[i][x][extra] != -1) return memo[i][x][extra];
    // 不发
    int no = helper(i + 1, x, extra);
    // 发一次
    int one = n + 1;
    if (x >= a[i] / 2) {
        one = helper(i + 1, x - a[i] / 2, extra) + 1;
    }
    // 多发
    int multi = n + 1;
    if (x >= a[i] && !extra) { // 未多发过
        multi = helper(i + 1, x - a[i], true) + 1;
    }
    return memo[i][x][extra] = min({no, one, multi});
}

int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = helper(0, x, false);
    if (ans == n + 1) cout << -1;
    else cout << ans;
}