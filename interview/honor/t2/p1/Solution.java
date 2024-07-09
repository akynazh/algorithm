package interview.honor.t2.p1;


import java.util.HashMap;
import java.util.Map;

public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回合并后的结果的数量即可
     * @param A string字符串一维数组 数组A
     * @param B string字符串一维数组 数组B
     * @return int整型
     */
    Map<Integer, Integer> insertMap = new HashMap<>();
    String[] originArr;
    String[] newArr;
    int sum = 0;
    public int combineArrays (String[] A, String[] B) {
        originArr = A;
        newArr = B;
        if (B.length == 1) return A.length + 1;
        for (int i = 1; i <= (A.length + 1); i++) {
            insertMap.put(0, i);
            recurInsert(1);
        }
        return sum;
    }

    private void recurInsert(int idx) {
        if (idx == newArr.length) {
            sum++;
            return;
        }
        int prev = insertMap.get(idx - 1);
        for (int i = prev; i <= (originArr.length + 1); i++) {
            insertMap.put(idx, i);
            recurInsert(idx + 1);
        }
    }
}