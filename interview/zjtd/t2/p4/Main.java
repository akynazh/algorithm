package interview.zjtd.t2.p4;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:10 2023/8/20
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String st = sc.next();
        long ans = 0;
        for (int k = 1; k <= st.length(); k++) {
            for (int i = 0; i < st.length(); i++) {
                if (i + k <= st.length()) {
                    ans += getData(st.substring(i, i + k));
                }

            }
        }
        System.out.println(ans);
    }

    private static long getData(String s) {
        long ans = 0, cur = 1;
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1 || s.charAt(i) != s.charAt(i + 1)) {
                ans++;
            }
        }
        return ans;
    }
}
