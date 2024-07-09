package interview.pdd.t2.p2;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * @author jiangzhh
 * @date 2024/4/15
 */
public class Main {
    static int MOD = (int) (1e7 + 7);
    static int MAX_N = (int) 1e6;
    static int[] arr = new int[MAX_N];
    static int N;
    static Map<Integer, Boolean> remMap = new HashMap<>();

    static long getSum(int start, int end) {
        Set<Integer> integers = remMap.keySet();
        for (Integer v : integers) {
            if (v >= start && v < end) {
                return  0;
            }
        }
        long s = 0;
        for (int i = start; i < end; i++) {
            if (arr[i] == arr[i + 1]) {
                remMap.put(start, true);
                return 0;
            }
            s = s + arr[i];
        }
        return s + arr[end];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        if (N <= 1) {
            System.out.println(0);
            return;
        }
        long sum = 0;
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i < N; i++) {
                int end = i + len - 1;
                if (end >= N) break;
                sum = (sum + getSum(i, end)) % MOD;
            }
        }
        System.out.println(sum);
    }
}
