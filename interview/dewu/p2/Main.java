package interview.dewu.p2;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 18:51 2023/8/23
 */
public class Main {
    static int[] arr;
    static int desSum;
    static int len;
    static int curMinCount = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        len = n;
        desSum = sc.nextInt();
        boolean fastOk = false;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            if (arr[i] == desSum) fastOk = true;
        }
        if (fastOk) {
            System.out.println(1);
            return;
        }
        Arrays.sort(arr);
        if (arr[0] > desSum) System.out.println("No solution");
        getAns(0, 0, 0);
        if (curMinCount == Integer.MAX_VALUE) {
            System.out.println("No solution");
        } else {
            System.out.println(curMinCount);
        }
    }

    private static void getAns(int curCount, int curSum, int idx) {
        if (curCount >= curMinCount || curSum > desSum) return;
        if (curSum == desSum) {
            curMinCount = curCount;
            return;
        }
        if (idx < len) {
            getAns(curCount + 1, curSum + arr[idx], idx + 1);
            getAns(curCount, curSum, idx + 1);
        }
    }

}
