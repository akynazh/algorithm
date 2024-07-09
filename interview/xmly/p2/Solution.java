package interview.xmly.p2;

import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a int整型二维数组 
     * @return long长整型
     */
    public long queryMaxSum (int[][] a) {
        long[] dp = new long[a.length];
        int prev = a[0][0] >= a[1][0] ? 0 : 1;
        dp[0] = a[prev][0];
        for (int i = 1; i < a.length; i++) {
            int cur = a[0][i] >= a[1][i] ? 0 : 1;
            int minCur = cur == 0 ? 1 : 0;
            if (cur != prev) {
                dp[i] = dp[i - 1] + a[cur][i];
                prev = cur;
            } else {
                dp[i] = Math.max(dp[i - 1] - a[prev][i - 1] + a[cur][i],
                        dp[i - 1] + a[minCur][i]);
            }
        }
        return dp[a.length - 1];
    }
}