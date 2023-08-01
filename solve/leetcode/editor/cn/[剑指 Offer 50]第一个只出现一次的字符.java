//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。 
//
// 示例 1: 
//
// 
//输入：s = "abaccdeff"
//输出：'b'
// 
//
// 示例 2: 
//
// 
//输入：s = "" 
//输出：' '
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
//
// Related Topics 队列 哈希表 字符串 计数 👍 339 👎 0


import com.sun.jmx.remote.internal.ArrayQueue;

import java.util.ArrayDeque;
import java.util.List;
import java.util.Queue;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public char firstUniqChar(String s) {
        if (s.length() == 0) return ' ';
        if (s.length() == 1) return s.charAt(0);
        int[] alp = new int[26];
        Queue<Character> lst = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int idx = c - 'a';
            if (alp[idx] == 0) {
                lst.add(c);
            }
            alp[idx] += 1;
        }
        while (!lst.isEmpty()) {
            Character ch = lst.poll();
            if (alp[ch - 'a'] == 1) return ch;
        }
        return ' ';

    }
}
//leetcode submit region end(Prohibit modification and deletion)
