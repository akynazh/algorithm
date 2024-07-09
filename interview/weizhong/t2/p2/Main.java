package interview.weizhong.t2.p2;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:48 2023/9/3
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        // Arrays.stream(arr).forEach(System.out::println);
        int c = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] <= arr[i - 1]) {
                int k = arr[i - 1] + 1;
                c += k - arr[i];
                arr[i] = k;
            }
        }
        System.out.println(c);
    }
}
