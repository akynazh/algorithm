package interview.klook.p2;

import java.util.HashMap;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 15:20 2023/10/3
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        System.out.println(getMaxLenOfSubString(input));
    }

    private static int getMaxLenOfSubString(String input) {
        int len = input.length();
        while (len > 1) {
            for (int i = 0; i < input.length(); i++) {
                try {
                    String st = input.substring(i, i + len);
                    if (checkIfHasNoDup(st)) {
                        return len;
                    }
                } catch (Exception e) {
                    break;
                }
            }
            len--;
        }
        return 1;
    }

    private static boolean checkIfHasNoDup(String st) {
        for (int i = 0; i < st.length(); i++) {
            if (st.substring(i + 1).indexOf(st.charAt(i)) != -1) return false;
        }
        return true;
    }
}

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int max = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                left = Math.max(left, map.get(c) + 1);
            }
            map.put(c, i);
            max = Math.max(max, i - left + 1);
        }
        return max;

    }
}


