package interview.oppo.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:52 2023/8/26
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    if (i < j) {
                        mx = Math.max((arr[i] + arr[j]) * Math.min(j - i, Math.abs(i + n - j)), mx);
                    } else {
                        mx = Math.max((arr[i] + arr[j]) * Math.min(i - j, Math.abs(j + n - i)), mx);
                    }
                }
            }
        }
        System.out.println(mx);
    }
}
