package interview.redbook.t3.p1;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author jiangzhh
 * @date 2024/3/24
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Boolean> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String st = sc.next();
            if (mp.get(st) == null) {
                System.out.println(st);
                mp.put(st, Boolean.TRUE);
            }
        }
    }
}
