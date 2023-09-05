package interview.dewu.p1;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 18:51 2023/8/23
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        boolean k = true;
        for (int i = arr.length - 1; i >= 0; i--) {
            if (k) queue.addFirst(arr[i]);
            else queue.addLast(arr[i]);
            k = !k;
        }
        int mx = Integer.MIN_VALUE;
        List<Integer> lst = queue.stream().collect(Collectors.toList());
        for (int i = 0; i < lst.size() - 1; i++) {
            mx = Math.max(mx, Math.abs(lst.get(i) - lst.get(i + 1)));
        }
        System.out.println(mx);
    }
}
