//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。 
//
// 
//
// 参考以下这颗二叉搜索树： 
//
//      5
//    / \
//   2   6
//  / \
// 1   3 
//
// 示例 1： 
//
// 输入: [1,6,3,2,5]
//输出: false 
//
// 示例 2： 
//
// 输入: [1,3,2,6,5]
//输出: true 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// 
//
// Related Topics 栈 树 二叉搜索树 递归 二叉树 单调栈 👍 662 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int[] postorder;
    public boolean verifyPostorder(int[] postorder) {
        this.postorder = postorder;
        return isOk(0, postorder.length - 1);
    }
    public boolean isOk(int left, int right) {
        if(left > right) return true;
        int i;
        for (i = left; i < right; i++) {
            if (postorder[i] > postorder[right]) break;
        }
        for (int j = i; j < right; j++) {
            if (postorder[j] < postorder[right]) return false;
        }
        return isOk(left, i - 1) && isOk(i, right - 1);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
