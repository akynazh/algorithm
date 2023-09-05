//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 3349 👎 0


import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<String> res = new ArrayList<>();
    StringBuilder sb = new StringBuilder();

    public List<String> generateParenthesis(int n) {
        dfs(n, n);
        return res;
    }

    void dfs(int l, int r) {
        if (l == 0 && r == 0) res.add(sb.toString());
        if (l > 0) { // 左括号剩余个数大于 0
            sb.append("(");
            dfs(l - 1, r);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (r > l) { // 如果右括号剩余个数比左括号多
            sb.append(")");
            dfs(l, r - 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
