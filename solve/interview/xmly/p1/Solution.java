package interview.xmly.p1;

import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 找出列表中任意两个时间的最小时间差的分钟数
     * @param timePoints string字符串ArrayList 时间列表
     * @return int整型
     */
    public int findMinDifference (ArrayList<String> timePoints) {
        int len = timePoints.size();
        int[] h = new int[len];
        int[] m = new int[len];
        for (int i = 0; i < len; i++) {
            String[] tpSplit = timePoints.get(i).split(":");
            h[i] = Integer.parseInt(tpSplit[0]);
            m[i] = Integer.parseInt(tpSplit[1]);
        }
        int mi = Integer.MAX_VALUE;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int h1 = h[i], m1 = m[i], h2 = h[j], m2 = m[j];
                if (h1 == h2) {
                    mi = Math.min(mi, Math.abs(m1 - m2));
                } else if (h1 < h2) {
                    int k1 = (h2 - h1) * 60 + (m2 - m1);
                    int k2 = (24 - h2) * 60 - m2 + h1 * 60 + m1;
                    mi = Math.min(mi, Math.min(k1, k2));
                } else {
                    int k1 = (h1 - h2) * 60 + (m1 - m2);
                    int k2 = (24 - h1) * 60 - m1 + h2 * 60 + m2;
                    mi = Math.min(mi, Math.min(k1, k2));
                }
            }
        }
        return mi;
    }
}