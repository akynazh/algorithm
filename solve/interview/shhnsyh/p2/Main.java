package interview.shhnsyh.p2;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:44 2023/8/5
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lst.add(sc.nextInt());
        }
        lst.sort(Comparator.comparingInt(o -> o));
        List<Integer> lst1 = new ArrayList<>();
        List<Integer> lst2 = new ArrayList<>();
        lst.forEach(v -> {
            if (v % 2 == 1) {
                lst1.add(v);
            } else {
                lst2.add(v);
            }
        });
        if (lst1.isEmpty() || lst2.isEmpty()) {
            System.out.println(1);
            return;
        }
        System.out.println(Math.max(solve(lst1, lst2, 1),
                solve(lst1, lst2, 2)));
    }

    private static int solve(List<Integer> lst1, List<Integer> lst2, int needType) {
        List<Integer> resList = new ArrayList<>();
        int i = 0, j = 0;
        if (needType == 2) {
            resList.add(lst1.get(i));
            i++;
        } else if (needType == 1) {
            resList.add(lst2.get(j));
            j++;
        }
        int cur = 0;
        while (i < lst1.size() && j < lst2.size()) {
            boolean success = true;
            Integer curVal = resList.get(cur);
            if (needType == 2) {
                Integer v = lst2.get(j);
                if (v > curVal) {
                    resList.add(v);
                    cur++;
                    j++;
                    needType = 1;
                } else {
                    j++;
                }
            } else if (needType == 1) {
                Integer v = lst1.get(i);
                if (v > curVal) {
                    resList.add(v);
                    cur++;
                    i++;
                    needType = 2;
                } else {
                    i++;
                }
            }
            if (!success) break;
        }
        if (needType == 1 && !lst1.isEmpty() && i < lst1.size() && lst1.get(i) > resList.get(cur)) {
            resList.add(lst1.get(i));
        }
        if (needType == 2 && !lst2.isEmpty() && j < lst2.size() && lst2.get(j) > resList.get(cur)) {
            resList.add(lst2.get(j));
        }

        return resList.size();
    }
}