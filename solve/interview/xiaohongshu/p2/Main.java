package interview.xiaohongshu.p2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int solve(int[] arr, int n, int k) {
        int cc = 0;
        for (;;) {
            boolean sorted = true;
            for (int i = 0; i < n - 1; i++)
                if (arr[i] > arr[i + 1]) {
                    sorted = false;
                    break;
                }
            if (sorted) break;
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    int t = i + 1, k1 = k;
                    while (t < n - 1 && k1 > 0) {
                        if (arr[t] > arr[t + 1]) {
                            k1--;
                            t++;
                        } else {
                            break;
                        }
                    }
                    cc++;
                    ArrayList<Integer> list = new ArrayList<>();
                    Arrays.sort(arr, i, i + k - k1);
                    for (int j = i; j < i + k - k1; j++) list.add(arr[j]);
                    for (int j = i + k - k1, u = 0; j < n; j++, u++) {
                        arr[i + u] = arr[j];
                    }
                    for (int j = i + n - (i + k - k1), u = 0; j < n; j++, u++) arr[j] =  list.get(u);
                }
            }
        }
        return cc;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(), n, k;
        int[] arr;
        for (int i = 0; i < T; i++) {
            n = sc.nextInt();
            k = sc.nextInt();
            arr = new int[n];
            for (int j = 0; j < n; j++)
                arr[j] = sc.nextInt();
            System.out.println(solve(arr, n, k));
        }
    }
}
