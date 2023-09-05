package interview.oppo.p2;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:08 2023/8/26
 */
public class Main {
    static int mod = (int) (1e9 + 7);
    static long sum = 0;

    static boolean isYuan(char c) {
        if (c == 'a' ||
                c == 'e' ||
                c == 'i' ||
                c == 'o' ||
                c == 'u'
        ) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String st = sc.next();
        recurSelect(0, 0, '0', '0', st);
        System.out.println(sum);
    }

    private static void recurSelect(int cur, int idx, char preYuan, char preFu, String st) {
        if (cur == 4) {
            sum = (sum + 1) % mod;
            return;
        }
        if (idx == st.length()) return;
        char ch = st.charAt(idx);
        if (isYuan(ch) && (cur == 0 || (cur == 3 && preYuan == ch))) {
            recurSelect(cur + 1, idx + 1, ch, preFu, st);
        }
        if (!isYuan(ch) && (cur == 1 || (cur == 2 && preFu == ch))) {
            recurSelect(cur + 1, idx + 1, preYuan, ch, st);
        }
        recurSelect(cur, idx + 1, preYuan, preFu, st);
    }
}
