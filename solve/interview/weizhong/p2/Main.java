package interview.weizhong.p2;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author akyna
 * @date 04/12 012 9:37 PM
 */
public class Main {
    public static void main(String[] args) {
        int[] energy = new int[100001];
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) energy[i] = sc.nextInt();
        int[] curMinSum = new int[100001];
        int[] curMinSumStart = new int[100001];
        curMinSum[0] = energy[0];
        curMinSumStart[0] = 0;
        for (int i = 1; i < energy.length; i++) {
            if (curMinSum[i-1]+energy[i] < energy[i]) {
                curMinSumStart[i] = curMinSumStart[i-1];
                curMinSum[i] = curMinSum[i-1]+energy[i];
            } else {
                curMinSumStart[i] = i;
                curMinSum[i] = energy[i];
            }
        }
        int mmin1 = Integer.MAX_VALUE, mmin1Idx = 0;
        for (int i = 0; i < curMinSum.length; i++) {
            if (curMinSum[i] < mmin1) {
                mmin1 = curMinSum[i];
                mmin1Idx = i;
            }
        }
        for (int i = curMinSumStart[mmin1Idx]; i <= mmin1Idx; i++) energy[i] = 0;
        for (int i = curMinSumStart[mmin1Idx]; i <= mmin1Idx; i++) curMinSum[i] = Integer.MAX_VALUE;
        mmin1 = Integer.MAX_VALUE;
        mmin1Idx = 0;
        for (int i = 0; i < curMinSum.length; i++) {
            if (curMinSum[i] < mmin1) {
                mmin1 = curMinSum[i];
                mmin1Idx = i;
            }
        }
        for (int i = curMinSumStart[mmin1Idx]; i <= mmin1Idx; i++) energy[i] = 0;
        int ssum = 0;
        for (int i = 0; i < energy.length; i++) ssum += energy[i];
        System.out.println(ssum);
    }
}
