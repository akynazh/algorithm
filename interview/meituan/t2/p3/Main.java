package interview.meituan.t2.p3;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 11:02 2023/8/12
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] cake = new int[n][m];
        int[] rowV = new int[n], colV = new int[m];
        int v;
        long ssum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v = sc.nextInt();
                cake[i][j] = v;
                rowV[i] += v;
                colV[j] += v;
                ssum += v;
            }
        }
        long mmin = (int) 1e8;
        mmin = getMmin(n, rowV, ssum, mmin);
        mmin = getMmin(m, colV, ssum, mmin);
        System.out.println(mmin);
    }

    private static long getMmin(int m, int[] colV, long ssum, long mmin) {
        for (int j = 0; j < m; j++) {
            long tmpSum = 0;
                for (int k = 0; k <= j; k++) tmpSum += colV[k];
            mmin = Math.min(mmin, Math.abs(ssum - tmpSum - tmpSum));
        }
        return mmin;
    }
}
