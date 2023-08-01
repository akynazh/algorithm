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

//runtime:2 ms
//memory:44 MB
