package interview.pdd.t2.p1;

import java.util.Scanner;

/**
 * @author jiangzhh
 * @date 2024/4/15
 */
public class Main {
    static int c = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String st = sc.next();
        int s = 0;
        if (N < 3) {
            System.out.println(c + " " + s);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (i + 2 < N) {
                s += getS(st.substring(i, i + 3));
                i += 2;
            }
        }
        System.out.println(c + " " + s);
    }

    private static int getS(String st) {
        c ++;
        int s = 0;
        char c1 = st.charAt(0), c2 = st.charAt(1), c3 = st.charAt(2);
        if (c1 >= 'P') s += c1 - 'P';
        else s += 'P' - c1;
        if (c2 >= 'D') s += c2 - 'D';
        else s += 'D' - c2;
        if (c3 >= 'D') s += c3 - 'D';
        else s += 'D' - c3;
        return s;
    }
}
