package interview.baidu.t1.p1;

import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong(), ssum = 0L;
        String s;
        long[] aMap = new long[5];
        for (; t > 0; t--) {
            s = sc.next();
            if (s.length() != 5) {
                System.out.println("No");
                continue;
            }
            for (int j = 0; j < s.length(); j++) {
                Character c = s.charAt(j);
                if (c.equals('B') && aMap[0] != t) {
                    ssum++;
                    aMap[0] = t;
                } else if (c.equals('a') && aMap[1] != t) {
                    ssum++;
                    aMap[1] = t;
                } else if (c.equals('i') && aMap[2] != t) {
                    ssum++;
                    aMap[2] = t;
                } else if (c.equals('d') && aMap[3] != t) {
                    ssum++;
                    aMap[3] = t;
                } else if (c.equals('u') && aMap[4] != t) {
                    ssum++;
                    aMap[4] = t;
                } else {
                    break;
                }
            }
            if (ssum == 5) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
            ssum = 0;
        }
    }
}