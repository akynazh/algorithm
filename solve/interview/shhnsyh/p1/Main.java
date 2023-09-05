package interview.shhnsyh.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:33 2023/8/5
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int x =  sc.nextInt();
            if (x < 10) {
                System.out.println(x % 2 == 0 ? 1 : 2);
            } else {
                System.out.println(1);
            }
        }
    }
}
