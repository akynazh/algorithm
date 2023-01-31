//写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下： 
//
// 
//F(0) = 0,   F(1) = 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1. 
//
// 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。 
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：n = 5
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 100 
// 
//
// Related Topics 记忆化搜索 数学 动态规划 👍 431 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    private final int mod = 1000000007;

    // 递归：超时
    //    public int fib(int n) {
//        if (n <= 1) return n;
//        return (fib(n-1) % mod + fib(n-2) % mod) % mod;
//    }
    // 数组
//    public int fib(int n) {
//        if (n <= 1) return n;
//        int[] fibs = new int[101];
//        fibs[0] = 0;
//        fibs[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            fibs[i] = (fibs[i-1] % mod + fibs[i-2] % mod) % mod;
//        }
//        return fibs[n];
//    }
    // 滚动数组
//    public int fib(int n) {
//        if (n <= 1) return n;
//        int a = 0, b = 0, c = 1;
//        for (int i = 2; i <= n; i++) {
//            a = b;
//            b = c;
//            c = (a + b) % mod;
//        }
//        return c;
//    }
    // 矩阵快速幂
    public int fib(int n) {
        if (n < 2) {
            return n;
        }
        int[][] mat = {{1, 1}, {1, 0}};
        int[][] res = myPow(mat, n - 1);
        return res[0][0];
    }
    private int[][] myPow(int[][] a, int n) {
        int[][] ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n % 2 == 1) {
                ret = mat_mul(ret, a);
            }
            n /= 2;
            a = mat_mul(a, a);
        }
        return ret;
    }
    private int[][] mat_mul(int[][] x, int[][] y) {
        int[][] res = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res[i][j] = (int)(((long)x[i][0] * y[0][j] + (long)x[i][1] * y[1][j]) % mod);
            }
        }
        return res;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
