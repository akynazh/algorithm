package practice.linklist;

import java.util.List;

/**
 * @Author jiangzhh
 * @Description: 输出单链表倒数第 K 个节点
 * @Date: Create in 23:37 2023/8/30
 */
public class Test1 {
    public static Node solve(Node head, int k) {
        int len = 1;
        Node cur = head;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        int idx = 1;
        cur = head;
        while (idx != len - k) {
            cur = cur.next;
            idx++;
        }
        return cur;
    }

    public static Node solve1(Node head, int k) {
        Node cur1 = head;
        Node cur2 = head;
        int k1 = k;
        for (int i = 0; i < k1; i++) {
            cur1 = cur1.next;
        }
        while (cur1 != null) {
            cur1 = cur1.next;
            cur2 = cur2.next;
        }

        return cur2;
    }
    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        System.out.println(solve(head, 2).val);
        System.out.println(solve1(head, 2).val);

    }
}
