package interview.huawei.pre.p2;

import java.util.Scanner;

/**
 * @author akyna
 * @date 04/12 012 10:51 AM
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char cc = Character.toLowerCase(chars[i]);
            if (cc == 'a'
                    || cc == 'e'
                    || cc == 'i'
                    || cc == 'o'
                    || cc == 'u') chars[i] = Character.toUpperCase(chars[i]);
            else chars[i] = Character.toLowerCase(chars[i]);
        }
        System.out.println(String.copyValueOf(chars));
    }
}
