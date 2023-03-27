package interview.xiaohongshu.p3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[100001], lt = new int[100000], rt = new int[100000], mt = new int[100000];
        for (int i = 1; i <= N; i++) arr[i] = sc.nextInt();
        int M = sc.nextInt();
        for (int i = 0; i < M; i++) lt[i] = sc.nextInt();
        for (int i = 0; i < M; i++) rt[i] = sc.nextInt();
        String mul = sc.next();
        for (int i = 0; i < M; i++) mt[i] = sc.nextInt();
        int l, r, m;
        char mc;
        for (int i = 0; i < M; i++) {
            l = lt[i];
            r = rt[i];
            mc = mul.charAt(i);
            m = mt[i];
            if (mc == '=') {
                for (int j = l; j <= r; j++) {
                    arr[j] = m;
                }
            } else if (mc == '&') {
                for (int j = l; j <= r; j++) {
                    arr[j] = arr[j] & m;
                }
            } else {
                for (int j = l; j <= r; j++) {
                    arr[j] = arr[j] | m;
                }
            }
        }
        for (int i = 1; i <= N; i++)
            System.out.print(arr[i] + " ");
    }
}
