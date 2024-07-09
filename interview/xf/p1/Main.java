package interview.xf.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 23:52 2023/8/29
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt(), r = sc.nextInt();
        double v = 3.14 * r * r * h / 1000;
        System.out.println((int)(Math.ceil(10.0 / v)));
    }
}
