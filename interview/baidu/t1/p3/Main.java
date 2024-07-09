package interview.baidu.t1.p3;

import java.util.Scanner;

public class Main {
    public static int x;
    public static boolean judge(String s) {
        if (s.length() == 1) return true;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
    public static boolean tryToAdd(int cur, StringBuilder sb) {
        String curS = sb.toString();
        for (int j = 0; j < curS.length(); j++) {
            if (judge(curS.substring(j))) cur++;
        }
        if (cur == x) {
            return true;
        } else if (cur > x) {
            sb.deleteCharAt(sb.length() - 1);
            return false;
        } else {
            for (int i = 0; i < 3; i++) {
                boolean flag;
                if (i == 0)  flag = tryToAdd(cur, sb.append("r"));
                else if (i == 1)  flag = tryToAdd(cur, sb.append("e"));
                else  flag = tryToAdd(cur, sb.append("d"));
                if (!flag) sb.deleteCharAt(sb.length() - 1);
                else return true;
            }

        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        sb.append("r");
        if (x == 1) System.out.println("r");
        else {
            tryToAdd(0, sb);
            System.out.println(sb);
        }
    }
}
