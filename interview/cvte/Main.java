package interview.cvte;

/**
 * @author akyna
 * @date 05/24 024 11:48 AM
 */
public class Main {
    public int[] solve(int[] arr) {
        int n = arr.length;
        int idx = n / 2 - 1;
        while (idx != 0) {
            int v = arr[idx], v1 = arr[2 * idx], v2 = arr[2 * idx + 1];
            if (v1 <= v2) {
                if (v > v1) {
                    arr[2 * idx] = v;
                    arr[idx] = v1;
                }
            } else {
                if (v > v2) {
                    arr[2 * idx + 1] = v;
                    arr[idx] = v2;
                }
            }
            idx--;
        }
        return arr;
    }
}
