//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 
//
// 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/ 
//
// Related Topics 递归 链表 👍 529 👎 0


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
    private ListNode resNode;
    private ListNode cur;
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;
        solve(head);
        cur.next = null;
        return resNode;
    }
    public void solve(ListNode node) {
        if (node.next == null) {
            resNode = node;
            cur = node;
            return;
        }
        solve(node.next);
        cur.next = node;
        cur = cur.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
