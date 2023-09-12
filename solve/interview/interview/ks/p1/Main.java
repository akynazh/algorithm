package interview.interview.ks.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:42 2023/9/8
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt();
        for (long i = 1; ; i++) {
            if (i * a % b == 1) {
                System.out.println(i);
                break;
            }
        }
    }
}
