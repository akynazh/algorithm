package interview.meituan.t2.p1;


import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 10:35 2023/8/12
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[200001];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int x = sc.nextInt(), y = sc.nextInt();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == x || arr[i] == y) {
                if (i + 1 < arr.length && (arr[i + 1] == x || arr[i + 1] == y)) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}

