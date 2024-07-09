package interview.huawei.t2.p2;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:11 2023/9/6
 */
public class Main {
    static int[][] mat;
    static int[][] dis;
    static int[][] rdis;
    static boolean[][] vis;
    static int m;
    static int n;

    static int dfs(int a, int b, int d, boolean dir) {
        int[] dx = new int[]{-1, 0, 1, 0};
        int[] dy = new int[]{0, -1, 0, 1};
        int mx = d;
        for (int j : dx) {
            for (int k : dy) {
                int nx = a + j, ny = b + k;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    if ((dir && mat[nx][ny] < mat[a][b]) || (!dir && mat[nx][ny] > mat[a][b])) {
                        vis[nx][ny] = true;
                        mx = Math.max(mx, dfs(nx, ny, d + 1, !dir));
                        vis[nx][ny] = false;
                    }
                }
            }
        }
        return mx;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        mat = new int[m][n];
        dis = new int[m][n];
        rdis = new int[m][n];
        vis = new boolean[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = sc.nextInt();
        int mx = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                vis[i][j] = true;
                dis[i][j] = dfs(i, j, 0, true);
                rdis[i][j] = dfs(i, j, 0, false);
                vis[i][j] = false;
                mx = Math.max(mx, Math.max(dis[i][j], rdis[i][j]));
            }
        System.out.println(mx);
    }
}
