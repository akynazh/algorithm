import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * 小红书的推荐帖子列表为[0,n]，其中所有的帖子初始状态为”普通“，现在运营同学把其中的一些帖子区间标记为了”精华“。
 * <p>
 * 输入描述
 * 第一行输入两个正整数n,m,k，代表初始帖子列表长度，精华区间的数量，以及运营同学准备截取的长度。
 * <p>
 * 接下来的m行，每行输入两个正整数li,ri，代表第i个区间。
 * <p>
 * 1 ≤ k ≤ n ≤ 1000000000
 * <p>
 * 1 ≤ m ≤ 100000
 * <p>
 * 0 ≤ li < ri ≤ n
 * <p>
 * 保证任意两个区间是不重叠的。
 * <p>
 * 输出描述
 * 一个正整数，代表最多的精华帖子数量。
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt(), l, r;
        boolean[] tps = new boolean[n + 1];
        int[] dp = new int[n + 1];
        Map<Integer, Integer> tmap = new HashMap<>();
        while (m-- != 0) {
            l = sc.nextInt();
            r = sc.nextInt();
            for (int i = r; i >= l; i--) {
                tps[i] = true;
                Integer ll = tmap.getOrDefault(i, n + 2);
                if (ll > l) {
                    tmap.put(i, l);
                }
            }
        }
        dp[0] = 0;
        int mmax = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = i - 1 - dp[i - 1], newDp;
            boolean b = tmp >= 0 && tps[tmp] && i - tmp - 1 >= k;
            if (tps[i]) {
                int ll = tmap.get(i);
                int cc = i - ll;
                if (cc >= k) {
                    System.out.println(k);
                    break;
                } else {
                    if (b) {
                        newDp = dp[i - 1];
                    } else {
                        newDp = dp[i - 1] + 1;
                    }
                    dp[i] = Math.max(newDp, cc);
                }
            } else {
                if (b) {
                    newDp = dp[i - 1] - 1;
                } else {
                    newDp = dp[i - 1];
                }
                dp[i] = newDp;
            }
            mmax = Math.max(mmax, dp[i]);
        }
        System.out.println(mmax);
    }
}
