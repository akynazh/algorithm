//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
//
// Related Topics 字符串 回溯 👍 651 👎 0


import java.util.*;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String[] permutation(String s) {
        List<String> ret = new ArrayList<>();
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        do {
            ret.add(new String(arr));
        } while (nextPermutation(arr));
        return ret.toArray(new String[0]);
    }

    public boolean nextPermutation(char[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--; // 找到尽可能靠右的较小者
        if (i < 0) return false;
        int j = arr.length - 1; // 找到尽可能小的较大者
        while (j >= 0 && arr[i] >= arr[j]) j--;
        // 交换较小者和较大者
        swap(arr, i, j);
        // 将较大者之后的数据串反转
        int left = i + 1, right = arr.length - 1;
        while (left < right) {
            swap(arr, left, right);
            left++;
            right--;
        }
        return true;
    }

    public void swap(char[] arr, int i, int j) {
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
//    private List<String> res = new LinkedList<>();
//    private List<Character> chars = new ArrayList<>();
//    private Map<String, Integer> preMap = new HashMap<>();
//    private Integer total;
//    public void recur(String s) {
//        if (s.length() == total) res.add(s);
//        else {
//            for (int i = 0; i < chars.size(); i++) {
//                Character ch = chars.get(i);
//                if (ch == null) continue;
//                String tmp = s + ch;
//                if (preMap.get(tmp) == null) {
//                    chars.set(i, null);
//                    recur(tmp);
//                    preMap.put(tmp, 1);
//                    chars.set(i, ch);
//                }
//            }
//        }
//    }
//    public String[] permutation(String s) {
//        total = s.length();
//        for (int i= 0 ; i < s.length(); i++) chars.add(s.charAt(i));
//        recur("");
//        return res.toArray(new String[0]);
//    }
}
//leetcode submit region end(Prohibit modification and deletion)
