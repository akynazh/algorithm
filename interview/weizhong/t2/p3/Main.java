package interview.weizhong.t2.p3;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:59 2023/9/3
 */
public class Main {
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    static Map<Integer, Integer> mp = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), u = sc.nextInt(), v = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                int end = j + i - 1 < n ? j + i - 1 : n - 1;
                res += solve2(arr, j, end, u, v);
            }
        }
        System.out.println(res);
    }

    private static int solve2(int[] arr, int start, int end, int u, int v) {
        Integer kk = mp.getOrDefault(start, -1);
        if (kk == end) return 0;
        mp.put(start, end);
        long sm = 0;
        for (int i = start; i <= end; i++) {
            sm += arr[i];
        }
        int len = end - start + 1;
        long x = gcd(sm, len);
        if (sm / x == u && len / x == v) return 1;
        return 0;
    }
}
