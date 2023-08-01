//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，
//等等。 
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
//
// Related Topics 数学 二分查找 👍 351 👎 0


import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    private Stack<Integer> getChars(int n) {
        Stack<Integer> lst = new Stack<>();
        if (n == 0) {
            lst.add(0);
            return lst;
        }
        while (n != 0) {
            lst.add(n % 10);
            n /= 10;
        }
        return lst;
    }
    public int findNthDigit(int n) {
        int d = 1, count = 9;
        while (n > (long) d * count) { // 找到当前 n 所在的数字的位数 d 和 n 在当前位数的第几位
            n -= d * count;
            d++;
            count *= 10;
        }
        int index = n - 1;
        int start = (int) Math.pow(10, d - 1); // 当前位数 d 的第一个数
        int num = start + index / d; // 找到当前 n 所在的数字
        int digitIndex = index % d; // 找到当前 n 是所在数字的第几位
        return (num / (int)(Math.pow(10, d - digitIndex - 1))) % 10;
//        int k = 0;
//        while (n >= 0) {
//            Stack<Integer> chars = getChars(k);
//            while (!chars.empty()) {
//                int v = chars.pop();
//                n--;
//                if (n < 0) {
//                    return v;
//                }
//            }
//            k++;
//        }
//        return k;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
