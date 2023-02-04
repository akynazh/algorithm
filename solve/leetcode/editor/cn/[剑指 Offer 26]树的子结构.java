//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构) 
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 给定的树 A: 
//
// 3 / \ 4 5 / \ 1 2 给定的树 B： 
//
// 4 / 1 返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
//
// Related Topics 树 深度优先搜索 二叉树 👍 687 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {val = x;}
}
class Solution {
    private TreeNode originB;
    private TreeNode originA;
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        originA = A;
        originB = B;
        if (A == null || B == null) return false;
        return solve(A, B);
    }
    private boolean solve(TreeNode A, TreeNode B) {
        if (A == null) return false;
        if (A.val == B.val) {
            if (B.left == null && B.right == null) {
                return true;
            } else if (B.left == null) {
                return solve(A.right, B.right);
            } else if (B.right == null) {
                return solve(A.left, B.left);
            } else {
                if (solve(A.right, B.right) && solve(A.left, B.left)) {
                    return true;
                } else {
                    return solve(A.right, originB) || solve(A.left, originB);
                }
            }
        } else {
            return solve(A.left, originB) || solve(A.right, originB);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
