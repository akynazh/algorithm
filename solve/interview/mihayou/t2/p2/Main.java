package interview.mihayou.t2.p2;


import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:46 2023/8/13
 */
public class Main {
    static int MAX_N = (int) 1e5 + 1;
    static int[] parent = new int[MAX_N];
    static int[] dist = new int[MAX_N];
    static boolean[] isLeave = new boolean[MAX_N];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int from, to;
        Arrays.fill(isLeave, true);
        Arrays.fill(parent, 1);
        int a, b;
        for (int i = 0; i < (n - 1); i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            from = Math.min(a, b);
            to = Math.max(a, b);
            parent[to] = from;
            isLeave[from] = false;
        }
        int c = 1;
        dist[1] = 0;
        for (int i = 2; i <= n; i++) {
            dist[i] = getDist(0, i);
        }
        for (int i = 2; i <= n; i++) {
            if (dist[i] <= k) c++;
            if (isLeave[i] && dist[i] < k) {
                c += k - dist[i];
            }
        }
        System.out.println(c);
    }
    static int getDist(int c, int t) {
        if (t == 1) return c;
        return getDist(c + 1, parent[t]);
    }
}
