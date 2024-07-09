package interview.shumei.p2;

import java.util.Scanner;

/**
 * @author akyna
 * @date 05/12 012 8:26 PM
 */
public class Main {
    public int solve(int n) {
        if (n == 1) return 1;
        int idx = 1, num = 2;
        while (true) {
            if (num % 2 == 0 || num % 3 == 0 || num % 7 == 0) {
                idx++;
                if (idx == n) return num;
            }
            num++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main main = new Main();
        while (sc.hasNext()) {
            int n = sc.nextInt();
            if (n == 0) break;
            System.out.println(main.solve(n));
        }
    }
}
