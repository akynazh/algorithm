//给定一个长度为 n 的链表 head 
//
// 对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。 
//
// 返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i 个节点没有下一个更大的节点
//，设置 answer[i] = 0 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [2,1,5]
//输出：[5,5,0]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [2,7,4,3,5]
//输出：[7,0,5,5,0]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数为 n 
// 1 <= n <= 10⁴ 
// 1 <= Node.val <= 10⁹ 
// 
//
// Related Topics 栈 数组 链表 单调栈 👍 290 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

import java.util.ArrayList;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/* 单调栈
class Solution {
    private int[] ans;
    private final Deque<Integer> st = new ArrayDeque<>(); // 单调栈（节点值）

    public int[] nextLargerNodes(ListNode head) {
        f(head, 0);
        return ans;
    }

    private void f(ListNode node, int i) {
        if (node == null) {
            ans = new int[i]; // i 就是链表长度
            return;
        }
        f(node.next, i + 1);
        while (!st.isEmpty() && st.peek() <= node.val)
            st.pop(); // 弹出无用数据
        if (!st.isEmpty())
            ans[i] = st.peek(); // 栈顶就是第 i 个节点的下一个更大元素
        st.push(node.val);
    }
}
*/

class Solution {

    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> answer = new ArrayList<>();
        int len = 0;
        ListNode curNode = head;
        while (curNode != null) {
            len ++;
            curNode = curNode.next;
        }
        int cur;
        for (int i = 0; i < len; i++) {
            cur = i;
            curNode = head;
            while (cur != 0) {
                curNode = curNode.next;
                cur--;
            }
            int curVal = curNode.val, hasBigger = 0, firstBig = 0;
            curNode = curNode.next;
            while (curNode != null) {
                if (curNode.val > curVal) {
                    hasBigger = 1;
                    firstBig = curNode.val;
                    break;
                }
                curNode = curNode.next;
            }
            if (hasBigger == 1) {
                answer.add(firstBig);
            } else {
                answer.add(0);
            }
        }
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
//leetcode submit region end(Prohibit modification and deletion)
