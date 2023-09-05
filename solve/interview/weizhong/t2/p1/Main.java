package interview.weizhong.t2.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:39 2023/9/3
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        boolean[] vis = new boolean[50001];
        int len = 0;
        for (int v : arr) {
            if (vis[v]) {
                break;
            }
            len++;
            vis[v] = true;
        }
        System.out.println(len);
    }
}
