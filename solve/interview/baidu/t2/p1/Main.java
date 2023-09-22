package interview.baidu.t2.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:53 2023/9/12
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int m, n;
        for (int i = 0; i < t; i++) {
            m = sc.nextInt();
            n = sc.nextInt();
            if ((m % 2 == 0 && n % 2 != 0) || (m % 2 != 0 && n % 2 == 0)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
