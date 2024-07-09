//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。 
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−2³¹, 231 − 1] ，就返回 0。 
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
// 
//
// 示例 1： 
//
// 
//输入：x = 123
//输出：321
// 
//
// 示例 2： 
//
// 
//输入：x = -123
//输出：-321
// 
//
// 示例 3： 
//
// 
//输入：x = 120
//输出：21
// 
//
// 示例 4： 
//
// 
//输入：x = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// -2³¹ <= x <= 2³¹ - 1 
// 
//
// Related Topics 数学 👍 3869 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int reverse(int x) {
        if (x == 0) return 0;
        String st = String.valueOf(x);
        StringBuilder sb = new StringBuilder();
        if (st.charAt(0) == '-') {
            sb.append('-');
            st = st.substring(1);
        }
        StringBuilder sb1 = new StringBuilder(st);
        StringBuilder sb2 = sb1.reverse();
        String st1 = sb2.toString();
        int idx = -1;
        for (int i = 0; i < st1.length() && st1.charAt(i) == '0'; i++) {
            idx = i;
        }
        if (idx != -1) {
            st1 = st1.substring(idx + 1);
        }
        long k = Long.valueOf(st1);
        if (sb.toString() == "-" && k > 2147483648L) return 0;
        if (sb.toString() != "-" && k > 2147483647L) return 0;
        StringBuilder res = sb.append(st1);
        return Integer.valueOf(res.toString());
    }
}
//leetcode submit region end(Prohibit modification and deletion)
