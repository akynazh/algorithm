package interview.meituan.t2.p5;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 11:27 2023/8/12
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] val = new int[100001];
        for (int i = 1; i <= n; i++) {
            val[i] = sc.nextInt();
        }
        int x, y;
        boolean[] isRed = new boolean[n + 1];
        List<List<Integer>> mmap = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            mmap.add(new ArrayList<>());
        }
        for (int i = 0; i < (n - 1); i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            mmap.get(x).add(y);
        }
        for (int i = 1; i < mmap.size(); i++) {
            List<Integer> lst = mmap.get(i);
            for (Integer v : lst) {
                if (!isRed[i] && !isRed[v] && isNice(val[i], val[v])) {
                    isRed[i] = true;
                    isRed[v] = true;
                }
            }
        }
        int c = 0;
        for (boolean b : isRed) {
            if (b) c++;
        }
        System.out.println(c);
    }

    private static boolean isNice(int x, int y) {
        long v = (long) x * y;
        int i = 1;
        while(true) {
            long u = i * i;
            if (v == u) return true;
            if (u > v) break;
            i++;
        }
        return false;
    }
}
