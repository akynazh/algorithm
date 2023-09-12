package interview.tx.t1.p1;

import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:31 2023/9/10
 */
public class Main {
    static int N = (int)1e5+1;
    static String[] tree = new String[N];
    static int res = 0;

    static void dfs(int c1, int c0, int idx, int len) {
        if (tree[idx].equals("1")) c1++;
        if (tree[idx].equals("0")) c0++;
        if (2 * idx > len || 2 * idx + 1 > len
                || (tree[2 * idx].equals("#") && tree[2 * idx + 1].equals("#"))) {
            if (c1 > c0) res ++;
            return;
        }
        if (!tree[2 * idx].equals("#")) dfs(c1, c0, 2 * idx, len);
        if (!tree[2 * idx + 1].equals("#")) dfs(c1, c0, 2 * idx + 1, len);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        input = input.substring(1, input.length() - 1);
        String[] strs = input.split(",");
        for (int i = 0; i < strs.length; i++) tree[i + 1] = strs[i];
        dfs(0, 0, 1, strs.length);
        System.out.println(res);
    }
}
