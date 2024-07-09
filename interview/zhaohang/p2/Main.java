package interview.zhaohang.p2;

import java.util.Scanner;

public class Main {

    static int solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt(), idx = 0, c_rep = 0;
        String st = sc.next();
        char[] chars = st.toCharArray();
        while (idx < st.length()) {
            char ch = chars[idx];
            int c = 1;
            for (int i = idx + 1; i < st.length(); i++) {
                if (chars[i] == ch) c++;
            }
            idx += c;
            if ((ch == '0' && c % a == 0) || (ch == '1' && c % b == 0)) continue;
            while (idx < st.length() && ((ch == '0' && c % a != 0) || (ch == '1' && c % b != 0))) {
                chars[idx] = ch;
                c_rep++;
                c++;
                idx++;
            }
            if (((ch == '0' && c % a != 0) || (ch == '1' && c % b != 0))) {
                return -1;
            }
        }
        return c_rep;
    }
    public static void main(String[] args) {
        System.out.println(solve());
    }
}
