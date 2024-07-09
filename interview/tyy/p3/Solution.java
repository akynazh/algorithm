package interview.tyy.p3;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:28 2023/9/14
 */
import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a string字符串
     * @param b string字符串
     * @return int整型
     */
    public int countSubstring (String a, String b) {
        // write code here
        Map<String, Integer> mp = new HashMap<>();
        int res = 0;
        int maxLen = Math.min(a.length(), b.length());
        for (int len = 1; len <= maxLen; len++) {
            for (int j = 1; j < a.length(); j++) {
                if (j + len - 1 >= a.length()) {
                    mp.put(a.substring(j, a.length() - 1), 1);
                    break;
                } else {
                    mp.put(a.substring(j, j + len - 1), 1);
                }
            }
        }
        for (int len = 1; len <= maxLen; len++) {
            for (int j = 1; j < b.length(); j++) {
                String t;
                int k = j + len - 1;
                if (k >= b.length()) {
                    t = b.substring(j, b.length() - 1);
                } else {
                    t = b.substring(j, k);
                }
                if (mp.getOrDefault(t, 0) == 1) {
                    res++;
                    mp.remove(t);
                }
                if (k >= b.length()) break;;
            }
        }
        return res;
    }
}
