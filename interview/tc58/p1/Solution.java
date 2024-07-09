package interview.tc58.p1;
import java.util.*;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:20 2023/9/16
 */
public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算需要的分数线
     * @param m int整型 晋级和淘汰数量闭区间左值
     * @param n int整型 晋级和淘汰数量闭区间右值
     * @param scores int整型一维数组 候选项目组分数
     * @return int整型
     */
    public int calculate (int m, int n, int[] scores) {
        Arrays.sort(scores);
        Set<Integer> res = new HashSet<>();
        int leftEnd = m - 1;
        for (int i = 1; ; i++) {
            int score = scores[leftEnd] + i;
            int rightStart = leftEnd + 1;
            while (rightStart < scores.length && scores[rightStart] < score) {
                rightStart++;
            }
            if (rightStart < n && (scores.length - rightStart) >= m
            && (scores.length - rightStart) <= n) {
                res.add(score);
            } else {
                break;

            }
        }
        return res.size() != 0 ? res.size() : -1;
    }
}