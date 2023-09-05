package interview.mi.p2;
// java interview.mi.p2.Main

import java.util.*;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 16:29 2023/9/2
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String data = sc.next();
        String[] dataList = data.split(",");

        List<Node> nodeList = new ArrayList<>();
        for (String v : dataList) {
            int i = v.indexOf(":");
            int mah = Integer.valueOf(v.substring(0, i));
            int minStart = Integer.valueOf(v.substring(i + 1));
            nodeList.add(new Node(mah, minStart));
        }
        nodeList.sort((o1, o2) -> {
            if (o1.minStart < o2.minStart) return 1;
            else if (o1.minStart.equals(o2.minStart)) return o1.mah - o2.mah;
            else return -1;
        });
        // System.out.println(nodeList);
        int res = nodeList.get(nodeList.size() - 1).minStart;
        for (int i = nodeList.size() - 2; i >= 0; i--) {
            Node n = nodeList.get(i);
            res = Math.max(res + n.mah, n.minStart);
        }
        if (res > 4800) System.out.println(-1);
        else System.out.println(res);
    }
}
class Node {
    Integer minStart;
    Integer mah;
    Node(Integer mah, Integer minStart) {
        this.mah = mah;
        this.minStart = minStart;
    }

    @Override
    public String toString() {
        return "minStart: " + minStart + " mah: " + mah + "\n";
    }
}