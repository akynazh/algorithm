package practice.linklist;

/**
 * @Author jiangzhh
 * @Description: 判断链表是否有环 # 快慢指针
 * @Date: Create in 23:51 2023/8/30
 */
public class Test2 {
    boolean hasLoop(Node head) {
        Node fast = head, slow = head;
        while (slow != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true;
        }
        return false;
    }
}
