#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int mat[110][110];
    int getSum1(int a) {
        int ans = 0;
        while(a) {
            int t = a % 10;
            a /= 10;
            ans += t;
        }
        return ans;
    }
    int getSum(int a, int b) {return getSum1(a) + getSum1(b);}
    
public:
    int movingCount(int m, int n, int k) {
        memset(mat, 0, sizeof(mat));
        mat[0][0] = 1;
        int steps = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !mat[nx][ny] && getSum(nx, ny) <= k) {
                    q.push(make_pair(nx, ny));
                    steps++;
                    mat[nx][ny] = 1;
                }
            }
        }
        return steps;
    }
};
int main() {
    
    Solution solution;
    int ans = solution.movingCount(2, 3, 1);
    cout << ans << endl;
    return 0;
}
