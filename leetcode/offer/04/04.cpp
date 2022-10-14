#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (!matrix.size() || !matrix[0].size()) return 0; // 输入{{}}，matrix.size()不为0！！！！！！
    int row = matrix.size(), col = matrix[0].size();
    for (int i = 0; i < row; i++) {
      if (target >= matrix[i][0] && target <= matrix[i][col - 1]) {
        for (int j = 0; j < col; j++)
          if (target == matrix[i][j]) return true;
      }
    }
    for (int i = 0; i < col; i++) {
      if (target >= matrix[0][i] && target <= matrix[row - 1][i]) {
        for (int j = 0; j < row; j++)
          if (target == matrix[j][i]) return true;
      }
    }
    return false;
  }
};
int main() {
  int target, t;
  cin >> target;
//   vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> matrix = {{}};
  Solution solution;
  bool ans = solution.findNumberIn2DArray(matrix, target);
  cout << ans << endl;
  return 0;
}