//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指
//向链表中的任意节点或者 null。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// 示例 2： 
//
// 
//
// 输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
// 
//
// 示例 3： 
//
// 
//
// 输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
// 
//
// 示例 4： 
//
// 输入：head = []
//输出：[]
//解释：给定的链表为空（空指针），因此返回 null。
// 
//
// 
//
// 提示： 
//
// 
// -10000 <= Node.val <= 10000 
// Node.random 为空（null）或指向链表中的节点。 
// 节点数目不超过 1000 。 
// 
//
// 
//
// 注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-
//pointer/ 
//
// 
//
// Related Topics 哈希表 链表 👍 669 👎 0


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
//leetcode submit region begin(Prohibit modification and deletion)
// Definition for a Node.

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Map<Node, Integer> originMap = new HashMap<>();
        Map<Integer, Node> targetMap = new HashMap<>();
        Node resHead = new Node(head.val);
        Node cur = head, resCur = resHead;
        originMap.put(cur, 0);
        targetMap.put(0, resCur);
        int i = 1;
        while (cur.next != null) {
            resCur.next = new Node(cur.next.val);
            originMap.put(cur.next, i);
            targetMap.put(i, resCur.next);
            cur = cur.next;
            resCur = resCur.next;
            i++;
        }
        cur = head;
        resCur = resHead;
        while (cur != null) {
            if (cur.random != null) {
                resCur.random = targetMap.get(originMap.get(cur.random));
            }
            cur = cur.next;
            resCur = resCur.next;
        }
        return resHead;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
