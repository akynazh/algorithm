package interview.zhihu.p2;

import java.util.*;


public class Solution {
    public void solve(int[] scores, int[] num, int start, int end) {
        if (start < 0 || end < 0 || start > num.length - 1 || end > num.length - 1) return;
        if (start == end) {
            computeNum(scores, num, start);
            return;
        }
        int mi = Integer.MAX_VALUE, mid = -1;
        for (int i = start; i <= end; i++) {
            if (mi > scores[i]) {
                mi = scores[i];
                mid = i;
            }
        }
        computeNum(scores, num, mid);
        solve(scores, num, start, mid - 1);
        solve(scores, num, mid + 1, end);
    }

    private static void computeNum(int[] scores, int[] num, int idx) {
        if (idx < 0 || idx > num.length - 1) return;
        if (idx - 1 < 0) {
            num[idx] = compute(scores, num, idx, idx + 1);
        } else if (idx + 1 > num.length - 1) {
            num[idx] = compute(scores, num, idx, idx - 1);
        } else {
            int t1 = compute(scores, num, idx, idx + 1);
            int t2 = compute(scores, num, idx, idx - 1);
            num[idx] = Math.max(t1, t2);
        }
    }

    private static int compute(int[] scores, int[] num, int cur, int next) {
        int res;
        if (num[next] == 0) res = 1;
        else {
            if (scores[next] > scores[cur]) res = num[next] - 1;
            else if (scores[next] < scores[cur]) res = num[next] + 1;
            else res = num[next];
        }
        if (res < 1) res = 1;
        return res;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param scores int整型一维数组 分数
     * @return int整型
     */
    public int prize(int[] scores) {
        int[] num = new int[scores.length];
        solve(scores, num, 0, scores.length - 1);
        int ans = 0;
        for (int m : num) {
            ans += m;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.prize(new int[]{1, 1, 2}));
    }
}