import java.util.*;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int curCount = 1;
        boolean startLeft = true;
        while (!queue.isEmpty()) {
            ArrayList<Integer> lst = new ArrayList<>();
            int count = 0;
            for (int i = 0; i < curCount; i++) {
                TreeNode node = queue.poll();
                lst.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                    count++;
                }
                if (node.right != null) {
                    queue.add(node.right);
                    count++;
                }
            }
            if (!startLeft) {
                Collections.reverse(lst);
            }
            if (lst.size() > 0) {
                res.add(lst);
            }
            curCount = count;
            startLeft = !startLeft;
        }
        return res;
    }
}
//leetcode submit region end(Prohibit modification and deletion)