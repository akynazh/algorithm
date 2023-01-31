//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
//
// Related Topics 栈 递归 链表 双指针 👍 365 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

import java.util.Stack;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        Stack<Integer> st = new Stack<>();
        int len = 0;
        while (head != null) {
            st.push(head.val);
            len++;
            head = head.next;
        }
        int[] res = new int[len];
        int i = 0;
        while (!st.empty()) {
            res[i++] = st.pop();
        }
        return res;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
