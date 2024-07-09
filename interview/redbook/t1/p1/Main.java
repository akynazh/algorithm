package interview.redbook.t1.p1;

import java.util.Scanner;

public class Main {
    static String solve(int n, String s) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < n; i++) {
            int k = chars[i] - 'a' - 3;
            if (k < 0) k += 26;
            chars[i] = (char) (97 + k);
        }
        return String.copyValueOf(chars);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        System.out.println(solve(n, s));
    }
}
