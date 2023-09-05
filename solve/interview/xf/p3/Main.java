package interview.xf.p3;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 23:59 2023/8/29
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long y = sc.nextLong(), m = sc.nextLong(), d = sc.nextLong();
        long y1 = sc.nextLong(), m1 = sc.nextLong(), d1 = sc.nextLong();
        if (y1 < y) {
            System.out.println("no");
        } else if (y1 == y && m1 < m) {
            System.out.println("no");
        } else if (y1 == y && m1 == m && d1 < d) {
            System.out.println("no");
        } else {
            System.out.println("yes");
        }

    }
}
