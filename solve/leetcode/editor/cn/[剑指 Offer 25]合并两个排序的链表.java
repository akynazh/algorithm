//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
//
// 示例1： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4 
//
// 限制： 
//
// 0 <= 链表长度 <= 1000 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
//
// Related Topics 递归 链表 👍 311 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        ListNode cur1 = l1, pre1 = l1, cur2 = l2;
        while (cur1 != null && cur2 != null) {
            if (cur1.val > cur2.val) {
                if (cur1 == l1) {
                    ListNode tmp = new ListNode(cur2.val);
                    tmp.next = cur1;
                    l1 = tmp;
                    cur1 = l1;
                    pre1 = l1;
                } else {
                    ListNode tmp = new ListNode(cur2.val);
                    pre1.next = tmp;
                    tmp.next = cur1;
                    pre1 = tmp;
                }
                cur2 = cur2.next;
            } else {
                pre1 = cur1;
                cur1 = cur1.next;
            }
        }
        while (cur2 != null) {
            pre1.next = new ListNode(cur2.val);
            pre1 = pre1.next;
            cur2 = cur2.next;
        }
        return l1;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
