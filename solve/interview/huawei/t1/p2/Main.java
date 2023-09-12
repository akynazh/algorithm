package interview.huawei.t1.p2;

import java.util.*;

/**
 * @author akyna
 * @date 04/12 012 8:04 PM
 */
public class Main {
    static int[] value = new int[10001];
    static List<Integer> ids = new ArrayList<>();
    static Map<Integer, List<Integer>> childs = new HashMap<>();
    static int n;

    static int solve(int k, int curSum) {
        List<Integer> curChilds = childs.get(k);
        if (curChilds == null) return curSum;
        for (int t : curChilds) {
            int tmpSum = solve(t, curSum + value[t]);
            if (tmpSum > curSum) curSum = tmpSum;
        }
        return curSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int a, b, c;
        for (int i = 0; i < n; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            ids.add(a);
            if (childs.get(b) != null) {
                childs.get(b).add(a);
            } else {
                ArrayList<Integer> arr = new ArrayList<>();
                arr.add(a);
                childs.put(b, arr);
            }
            value[a] = c;
        }
        int mmax = Integer.MIN_VALUE;
        for (int id : ids) {
            int t = solve(id, value[id]);
            if (t > mmax) mmax = t;
        }
        System.out.println(mmax);
    }
}
