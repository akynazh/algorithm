package interview.redbook.t3.p3;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @author jiangzhh
 * @date 2024/3/24
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] notes = new long[n];
        long sum = 0L;
        for (int i = 0; i < n; i++) {
            notes[i] = sc.nextLong();
            sum += notes[i];
        }
        Arrays.sort(notes);
        long maxV = notes[n - 1];
        for (int i = 0; i < notes.length; i++) {
            if (notes[i] == maxV) System.out.println(sum);

        }
    }
}
