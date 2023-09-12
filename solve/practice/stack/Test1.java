package practice.stack;

import java.util.Scanner;
import java.util.Stack;

/**
 * @Author jiangzhh
 * @Description: 找出第一个更大的元素 -> 单调栈
 * @Date: Create in 20:01 2023/9/6
 */
public class Test1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Stack<Integer> stk = new Stack<>();
        // 若为循环数组, i < 2 * n , [i % n]
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.peek()] < arr[i]) {
                res[stk.pop()] = i;
            }
            stk.push(i);
        }
        for (int v : res) {
            System.out.print(v + " ");
        }
    }
}
