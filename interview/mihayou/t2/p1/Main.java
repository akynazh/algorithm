package interview.mihayou.t2.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:22 2023/8/13
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int x = sc.nextInt(), y = sc.nextInt();
        int x1 = sc.nextInt(), y1 = sc.nextInt();
        int x2 = sc.nextInt(), y2 = sc.nextInt();
        System.out.println(getMin(x, y, x1, y1, n, m) + getMin(x1, y1, x2, y2, n, m));
    }

    private static int getMin(int x, int y, int x1, int y1, int n, int m) {
        int c = 0;

        int lenX = Math.abs(x - x1), lenY = Math.abs(y - y1);
        int lenX1 = 0;
        if (x < x1) lenX1 = n - x1 + x;
        if (x > x1) lenX1 = n - x + x1;
        c += Math.min(lenX, lenX1);
        int lenY1 = 0;
        if (y < y1) lenY1 = m - y1 + y;
        if (y > y1) lenY1 = m - y + y1;
        c += Math.min(lenY, lenY1);
        return c;
    }
}
