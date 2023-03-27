package interview.zhaohang.p1;

import java.util.Scanner;

public class Main {
    static long solve() {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong(), b = sc.nextLong();
        if (b == 1 || a == b || a % b == 0) return 0;
        if (a <= b) return b - a;
        if (isZhi(a)) return Math.min(a - b, b - 1);
        long m = a / b;
        long k1 = m - 1 != 0 ? Math.abs(b - a / (m - 1)) : a, k2 = Math.abs(b - a / m), k3 = Math.abs(b - a / (m + 1));
        return k1 <= k2 ? (Math.min(k1, k3)) : (Math.min(k2, k3));
    }


    static boolean isZhi(long k) {
        long k1 = (long) Math.sqrt(k);
        for (long i = 2; i <= k1; i++)
            if (k % i == 0) return false;
        return true;
    }

    static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        boolean[] prime = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            prime[i] = true;
        }
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime[n];
    }

    public static void main(String[] args) {
        System.out.println(solve());
    }
}
