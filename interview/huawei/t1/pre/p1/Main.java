package interview.huawei.t1.pre.p1;

import java.util.Scanner;

/**
 * @author akyna
 * @date 04/12 012 10:47 AM
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] strings = s.split(" ");
        double len = 0;
        for (String t : strings) {
            len += t.length();
        }
        System.out.printf("%.2f", len / strings.length);
    }
}
