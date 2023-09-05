package interview.meituan.t2.p2;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 10:35 2023/8/12
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[100001];
        long ssum = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
            ssum += arr[i];
        }
        int x = sc.nextInt(), y = sc.nextInt();
        long ssumxy = 0;
        if (x < y) {
            for (int i = x; i < y; i++) ssumxy += arr[i];
        } else if (x > y) {
            for (int i = y; i < x; i++) ssumxy += arr[i];
        }
        System.out.println(Math.min(ssumxy, ssum - ssumxy));
    }
}
