package interview.honor.p1;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

/**
 * @author akyna
 * @date 04/27 027 6:11 PM
 */
public class Main {
    public static String solve(String st) {
        if (st.length() <= 1) return st;
        int[] flg = new int[st.length()];
        char[] res = new char[st.length()];
        ArrayList<Character> alps = new ArrayList<>();
        ArrayList<Character> nums = new ArrayList<>();
        for (int i = 0; i < st.length(); i++) {
            if (st.charAt(i) >= '0' && st.charAt(i) <= '9') {
                flg[i] = 0;
                nums.add(st.charAt(i));
            }
            else {
                flg[i] = 1;
                alps.add(st.charAt(i));
            }
        }
        nums.sort(new Comparator<Character>() {
            @Override
            public int compare(Character o1, Character o2) {
                return Integer.valueOf(o1) - Integer.valueOf(o2);
            }
        });
        alps.sort(new Comparator<Character>() {
            @Override
            public int compare(Character o1, Character o2) {
                if (o1 == o2) return 0;
                return o1 > o2 ? 1 : -1;
            }
        });
        int idx_nums = 0, idx_alps = 0;
        for (int i = 0; i < st.length(); i++) {
            if (flg[i] == 0) {
                res[i] = nums.get(idx_nums++);
            } else {
                res[i] = alps.get(idx_alps++);
            }
        }
        return String.valueOf(res);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int len = sc.nextInt();
            String st = sc.next();
            System.out.println(solve(st));
        }
    }
}
