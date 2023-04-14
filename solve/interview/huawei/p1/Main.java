package interview.huawei.p1;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author akyna
 * @date 04/12 012 7:05 PM
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        long ssum = 0;
        String st = sc.nextLine();
        int cnt = sc.nextInt();
        String[] strings = st.split(" ");
        for (String s : strings) {
            int t = Integer.parseInt(s);
            arr.add(t);
            ssum += t;
        }
        if (ssum <= cnt) System.out.println(-1);
        else if (arr.size() == 1) System.out.println(cnt);
        else {
            arr.sort((o1, o2) -> o2 - o1);
            int[] curSum = new int[arr.size()];
            curSum[0] = arr.get(0);
            for (int i = 1; i < arr.size(); i++) curSum[i] = arr.get(i) + curSum[i-1];
            for (int i = 1; i < arr.size(); i++) {
                if (arr.get(i).equals(arr.get(i - 1))) continue;
                int lim = arr.get(i);
                long newSum = ssum - (curSum[i-1] - (long) i * lim);
                if (newSum <= cnt) {
                    System.out.println(lim);
                    return;
                }
            }
            System.out.println(0);
        }
    }
}
