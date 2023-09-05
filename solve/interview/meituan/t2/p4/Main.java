package interview.meituan.t2.p4;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 11:54 2023/8/12
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String next = sc.next();
        int mmin = Integer.MAX_VALUE;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                mmin = Math.min(mmin, getLinkCount(next, i, n / i));
            }
        }
        System.out.println(mmin);
    }

    private static int getLinkCount(String next, int i, int i1) {
        return 0;
    }
}
