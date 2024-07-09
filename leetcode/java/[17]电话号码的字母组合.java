//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2585 👎 0


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    Map<Character, String> board = new HashMap<>();
    String st;
    List<String> res = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.trim().length() == 0) return res;
        st = digits.trim();
        board.put('2', "abc");
        board.put('3', "def");
        board.put('4', "ghi");
        board.put('5', "jkl");
        board.put('6', "mno");
        board.put('7', "pqrs");
        board.put('8', "tuv");
        board.put('9', "wxyz");
        solve(new StringBuilder(), 0);
        return res;
    }
    void solve(StringBuilder sb, int idx) {
        if (idx == st.length()) {
            res.add(sb.toString());
            return;
        }
        char c = st.charAt(idx);
        String s = board.get(c);
        for (int i = 0; i < s.length(); i++) {
            sb.append(s.charAt(i));
            solve(sb, idx + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)