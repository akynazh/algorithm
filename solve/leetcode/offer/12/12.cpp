#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        board1 = board;
        word1 = word;
        int m = board.size(), n = board[0].size();
        m1 = m; n1 = n;
        flag.resize(m);
        for (int i = 0; i < m; i++) flag[i].resize(n);
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                flag[i][j] = 1;
                if (solve(board[i][j], i, j, 0)) return true;
                flag[i][j] = 0;
            }
        return false;
    }
private:
    vector<vector<char>> board1;
    vector<vector<int>> flag;
    string word1;
    int m1, n1;
    bool solve(char ch, int m2, int n2, int idx) {
        if (ch != word1[idx]) return false;
        if (idx+1 == (int)word1.size()) return true;
        if (m2 < m1 - 1 && !flag[m2+1][n2]) {
            flag[m2+1][n2] = 1;
            if (solve(board1[m2+1][n2], m2+1, n2, idx+1)) return true;
            flag[m2+1][n2] = 0;
        }
        if (n2 < n1 - 1 && !flag[m2][n2+1]) {
            flag[m2][n2+1] = 1;
            if (solve(board1[m2][n2+1], m2, n2+1, idx+1)) return true;
            flag[m2][n2+1] = 0;
        }
        if (m2 > 0 && !flag[m2-1][n2]) {
            flag[m2-1][n2] = 1;
            if (solve(board1[m2-1][n2], m2-1, n2, idx+1)) return true;
            flag[m2-1][n2] = 0;
        }
        if (n2 > 0 && !flag[m2][n2-1]) {
            flag[m2][n2-1] = 1;
            if (solve(board1[m2][n2-1], m2, n2-1, idx+1)) return true;
            flag[m2][n2-1] = 0;
        }
        return false;
    }
};
int main() {
    
    Solution solution;
    
    return 0;
}