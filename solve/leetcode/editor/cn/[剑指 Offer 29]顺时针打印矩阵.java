//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= matrix.length <= 100 
// 0 <= matrix[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
//
// Related Topics 数组 矩阵 模拟 👍 498 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix.length == 0) return new int[]{};
        int k = 0, l1 = 0, l2 = 0, r1 = matrix.length - 1, r2 = matrix[0].length - 1;
        int[] res = new int[matrix.length * matrix[0].length];
        while (l1 <= r1 && l2 <= r2) {
            for (int i = l2; i <= r2; i++) res[k++] = matrix[l1][i];
            for (int i = l1 + 1; i <= r1; i++) res[k++] = matrix[i][r2];
            for (int i = r2 - 1; r1 != l1 && i >= l2; i--) res[k++] = matrix[r1][i];
            for (int i = r1 - 1; r2 != l2 && i > l1; i--) res[k++] = matrix[i][l2];
            l1++; l2++; r1--; r2--;
        }
        return res;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
