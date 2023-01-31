//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。 
//
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 示例 1: 
// 
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 964 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

import java.util.HashMap;
import java.util.Map;

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
    private int[] preorder;
    private Map<Integer, Integer> inorderDict;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        inorderDict = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderDict.put(inorder[i], i);
        }
        return recurseBuildTree(0, 0, inorder.length - 1);
    }
    private TreeNode recurseBuildTree(int preRoot, int inLeft, int inRight) {
        if (inLeft > inRight) return null;
        int rootVal = preorder[preRoot];
        TreeNode root = new TreeNode(rootVal);
        int midIdx = inorderDict.get(rootVal);
        root.left = recurseBuildTree(preRoot + 1, inLeft, midIdx - 1);
        root.right = recurseBuildTree(preRoot + 1 + (midIdx - 1 - inLeft + 1), midIdx + 1, inRight);
        return root;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
