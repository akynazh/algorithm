package interview.tx.t1.p2;

import java.sql.SQLOutput;
import java.util.*;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 21:09 2023/9/10
 */
class Node {
    int oriIdx;
    int val;
    Node(int a, int b) {
        oriIdx = a;
        val = b;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            List<Node> nodes = new LinkedList<>();
            int[] arrB = new int[n];
            for (int j = 0; j < n; j++) {
                nodes.add(new Node(j + 1, sc.nextInt()));
            }
            for (int j = 0; j < n - 1; j++) {
                arrB[j] = sc.nextInt();
            }
            nodes.sort(Comparator.comparingInt(x -> x.val));

            getMid(nodes);
            for (int k = 0; k < n - 1; k++) {
                int finalK = k;
                nodes.removeIf(node -> node.oriIdx == arrB[finalK]);
                getMid(nodes);
            }
            System.out.print("\n");
        }
    }

    private static void getMid(List<Node> nodes) {
        if (nodes.size() == 1) {
            System.out.print(nodes.get(0).val);
            return;
        }
        int v1 = nodes.get(nodes.size() / 2).val;
        int v2 = nodes.get(nodes.size() / 2 - 1).val;

        if (nodes.size() % 2 == 0) {
            if ((v1 + v2) % 2 == 0) {
                System.out.print((v1 + v2) / 2 + " ");
            } else {
                System.out.printf("%.1f ", (v1 + v2) / 2.0);
            }
        }
        else {
            System.out.print(v2 + " ");
        }
    }
}
