package interview.weizhong.p1;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * @author akyna
 * @date 04/12 012 8:54 PM
 */
public class Main {
    static void solve(int X, int Y, int L, int R) {
        List<Integer> arrX = new LinkedList<>();
        List<Integer> arrY = new LinkedList<>();
        while (X != 0) {
            arrX.add(X % 2);
            X /= 2;
        }
        while (Y != 0) {
            arrY.add(Y % 2);
            Y /= 2;
        }
        if (arrX.size() < arrY.size()) {
            int more0 = arrY.size() - arrX.size();
            for (int i = 0; i < more0; i++) arrX.add(0);
        } else {
            int more0 = arrX.size() - arrY.size();
            for (int i = 0; i < more0; i++) arrY.add(0);
        }
        int freeSpace = 0, count1 = 0;
        for (int i = arrX.size() - 1; i >= 0; i--) {
            if (arrX.get(i) == 1) {
                count1++;
                if (arrY.get(i) != 1) {
                    System.out.println(0);
                    return;
                }
            } else if (arrY.get(i) == 0 && arrX.get(i) != 0) {
                System.out.println(0);
                return;
            } else {
                freeSpace ++;
            }
        }
        if (count1 < L || count1 > R) {
            System.out.println(0);
            return;
        }
        int c1 = Math.min(freeSpace, R - count1);
        int ssum = 1;
        for (int i = 1; i <= c1; i++) {
            int j = i, v1 = 1, v2 = 1, curFreeSpace = freeSpace;
            while (j >= 1) {
                v1 *= j;
                v2 *= curFreeSpace;
                j--;
                curFreeSpace--;
            }
            ssum += v2 / v1;
        }
        System.out.println(ssum);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(), L, R, X, Y;
        while (T != 0) {
            T--;
            L = sc.nextInt();
            R = sc.nextInt();
            X = sc.nextInt();
            Y = sc.nextInt();
            solve(X, Y, L, R);
        }
    }
}
