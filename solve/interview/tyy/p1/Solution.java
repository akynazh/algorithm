package interview.tyy.p1;


public class Solution {
    private boolean isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串 
     * @return int整型
     */
    public int myCount (String str) {
        // write code here
        int total = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (isYuan(c)) {
                total++;
            } else if (Character.isUpperCase(c) && !isYuan(Character.toLowerCase(c))) {
                total++;
            }
        }
        return total;
    }
}