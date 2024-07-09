package interview.redbook.t3.p2;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author jiangzhh
 * @date 2024/3/24
 */
public class Main {
    static int ans = Integer.MAX_VALUE;
    static boolean flag = false;
    static int[] fans = new int[100];
    static int n, x;
    static int maxV = 0;
    static Map<String, Integer> mp = new HashMap<>();
    static int[] curSum = new int[100];

    static void solve(int c, int idx, int xx) {
        if (idx < 0 || c >= ans || xx > curSum[idx]) {
            return;
        }
        if (xx == curSum[idx]) {
            flag = true;
            ans = Math.min(c + idx + 1, ans);
            return;
        }
        String kk = "i" + idx + "x" + xx;
        Integer kkc = mp.get(kk);
        if (kkc != null && kkc == c) {
            return;
        }
        mp.put(kk, c);
        int curV = fans[idx], curV2 = fans[idx] / 2;
        if (xx - curV2 == 0 || xx - curV == 0) {
            ans = Math.min(c + 1, ans);
            flag = true;
            return;
        }
        if (xx - curV > 0) solve(c + 1, idx - 1, xx - curV);
        if (xx - curV2 > 0) solve(c + 1, idx - 1, xx - curV2);
        solve(c, idx - 1, xx);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        x = sc.nextInt();
        for (int i = 0; i < n; i++) {
            fans[i] = sc.nextInt();
            maxV += fans[i];
        }
        if (x > maxV) {
            System.out.println(-1);
        } else if (x == maxV) {
            System.out.println(n);
        } else {
            Arrays.sort(fans, 0, n);
            curSum[0] = fans[0];
            for (int i = 1; i < fans.length; i++) {
                curSum[i] = curSum[i - 1] + fans[i];
            }
            solve(0, n - 1, x);
            if (flag) {
                System.out.println(ans);
            } else {
                System.out.println(-1);
            }
        }
    }
}
