import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 小红的数组构造
 *
 * 小红希望你构造一个数组满足以下条件：
 *
 * 1. 数组共有n个元素，且所有元素两两不相等。
 *
 * 2. 所有元素的最大公约数等于k。
 *
 * 3. 所有元素之和尽可能小。
 *
 * 请你输出数组元素之和的最小值。
 */
public class Main {
    public int gcd(int a, int b) {
        if (a < b) return a;
        return gcd(b, a % b);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        List<Integer> arr = new ArrayList<>();
        int cv = k;
        arr.add(cv);
        while (--n != 0) {
            cv += k;
            arr.add(cv);
        }
        int s = 0;
        for (Integer v : arr) {
            s += v;
        }
        System.out.println(s);
    }
}
