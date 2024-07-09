package interview.klook.p1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 15:19 2023/10/3
 */
public class Main {
    static int res = Integer.MAX_VALUE;
    static List<Integer> arr;

    static void dfs(int steps, int idx) {
        if (idx >= arr.size() - 1) {
            res = Math.min(steps, res);
            return;
        }
        dfs(steps + 1, idx + 1);
        if (arr.get(idx) != 0) dfs(steps + 1, idx + arr.get(idx));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        String[] strings = input.split(",");
        arr = new ArrayList<>();
        for (String s : strings) {
            arr.add(Integer.parseInt(s));
        }
        int steps = 0;
        dfs(steps + 1, 1);
        if (arr.get(0) != 0) dfs(steps + 1, arr.get(0));
        System.out.println(res);
    }
}
