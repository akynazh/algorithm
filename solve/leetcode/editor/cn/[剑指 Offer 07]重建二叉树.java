
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

//runtime:1 ms
//memory:41.6 MB
