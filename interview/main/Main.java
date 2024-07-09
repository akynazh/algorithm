package interview.main;

import java.util.List;

/**
 * @author akyna
 * @date 05/06 006 5:35 PM
 */
public class Main {

    public static ListNode solve(ListNode node1, ListNode node2) {
        if (node1 == null) {
            return node2;
        } else if (node2 == null) {
            return node1;
        }
        ListNode node;
        if (node1.val <= node2.val) {
            node = new ListNode(node1.val);
            node1 = node1.next;
        } else {
            node = new ListNode(node2.val);
            node2 = node2.next;
        }
        ListNode root = node;
        while(node1 != null && node2 != null) {
            if (node1.val <= node2.val) {
                node.next = new ListNode(node1.val);
                node1 = node1.next;
            } else {
                node.next = new ListNode(node2.val);
                node2 = node2.next;
            }
            node = node.next;
        }
        if (node1 != null) node.next = node1;
        else {
            node.next = node2;
        }
        return root;
    }

    // 在合并链表的同时，删除所有重复的节点，只保留一个。
    public static ListNode solve1(ListNode node1, ListNode node2) {
        if (node1 == null) {
            return node2;
        } else if (node2 == null) {
            return node1;
        }
        ListNode node;
        if (node1.val <= node2.val) {
            node = new ListNode(node1.val);
            node1 = node1.next;
        } else {
            node = new ListNode(node2.val);
            node2 = node2.next;
        }
        ListNode root = node;
        while(node1 != null && node2 != null) {
            if (node1.val <= node2.val) {
                if (node.val != node1.val) {
                    node.next = new ListNode(node1.val);
                    node = node.next;
                }
                node1 = node1.next;
            } else {
                if (node.val != node2.val) {
                    node.next = new ListNode(node2.val);
                    node = node.next;
                }
                node2 = node2.next;
            }

        }
        if (node1 != null && node1.val != node.val) node.next = node1;
        else if (node2 != null && node2.val != node.val){
            node.next = node2;
        }
        return root;
    }
    public static void main(String[] args) {
/*
*
* 输入: l1 = 1->2->4, l2 = 1->3->4
输出: 1->1->2->3->4->4

* */
        ListNode node1 = new ListNode(1);
        node1.next = new ListNode(2);
        node1.next.next = new ListNode(4);
        ListNode node2 = new ListNode(1);
        node2.next = new ListNode(3);
        node2.next.next = new ListNode(4);
//        ListNode node = solve(node1, node2);
        ListNode node = solve1(node1, node2);
        while(node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}