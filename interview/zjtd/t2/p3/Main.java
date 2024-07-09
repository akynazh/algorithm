package interview.zjtd.t2.p3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:36 2023/8/20
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        if (n == 2) {
            System.out.println(0);
            return;
        }
        int k = (int) (sum / n);
        long ans = 0;
        List<Integer> lst = new ArrayList<>();
        int mmax = Integer.MIN_VALUE;
        for (int v : arr) {
            int abs = Math.abs(k - v);
            lst.add(abs);
            if (abs > mmax) mmax = abs;
        }
        boolean t = false;
        for (Integer v : lst) {
            if (v == mmax && !t) {
                t = true;
            } else {
                ans += v;
            }
        }
        System.out.println(ans);
    }
}
