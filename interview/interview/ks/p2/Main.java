package interview.interview.ks.p2;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:44 2023/9/8
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger v1 = new BigInteger(sc.next());
        BigInteger v2 = new BigInteger(sc.next());
        System.out.println(v1.multiply(v2));
    }
}
