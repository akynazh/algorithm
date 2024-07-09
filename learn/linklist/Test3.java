package practice.linklist;

/**
 * @Author jiangzhh
 * @Description: 反转链表
 * @Date: Create in 15:38 2023/8/31
 */
public class Test3 {
    Node solve(Node head) {
        Node pre = null;
        Node cur = head;
        while (cur != null) {
            Node next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}
