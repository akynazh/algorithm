package interview.shumei.p1;


/**
 * @author akyna
 * @date 05/12 012 8:19 PM
 */
public class Main {
    public int[] solve(int[] lst1, int[] lst2) {
        int idx1 = 0, idx2 = 0, idx = 0;
        int[] lst = new int[lst1.length + lst2.length];
        while (idx1 < lst1.length && idx2 < lst2.length) {
            if (lst1[idx1] <= lst2[idx2]) {
                lst[idx++] = lst1[idx1++];
            } else {
                lst[idx++] = lst2[idx2++];
            }
        }
        while (idx1 < lst1.length) lst[idx++] = lst1[idx1++];
        while (idx2 < lst2.length) lst[idx++] = lst1[idx2++];
        return lst;
    }
}
