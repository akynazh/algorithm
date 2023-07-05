//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 569 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        // NlogN
        /*
        Arrays.sort(arr);
        return Arrays.stream(Arrays.copyOfRange(arr, 0, k)).toArray();
        */

        // NlogK
        /*
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((v1, v2) -> v2 - v1);
        for (int num : arr) {
            if (pq.size() < k) {
                pq.offer(num);
            } else if (num < pq.peek()) {
                pq.poll();
                pq.offer(num);
            }
        }
        int[] res = new int[k];
        for (int i =  k - 1; i >= 0; i--) {
            res[i] = pq.poll();
        }
        return res;
        */

        // N
        if (k == 0 || arr.length == 0) return new int[0];
        if (k == arr.length) return arr;
        return quickSearch(arr, 0, arr.length - 1, k);
    }

    private int[] quickSearch(int[] nums, int lo, int hi, int k) {
//        int j = partition(nums, lo, hi);
        int j = partition1(nums, lo, hi);
        if (j == k) {
            return Arrays.copyOf(nums, j);
        }
        return j > k ? quickSearch(nums, lo, j - 1, k) : quickSearch(nums, j + 1, hi, k);
    }

    private int partition1(int[] nums, int lo, int hi) {
        int piv = nums[lo];
        while (lo < hi) {
            while (lo < hi && nums[hi] >= piv) hi--;
            nums[lo] = nums[hi];
            while (lo < hi && nums[lo] <= piv) lo++;
            nums[hi] = nums[lo];
        }
        nums[lo] = piv;
        return lo;
    }
    private int partition(int[] nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo + 1, j = hi;
        while (i <= j) {
            while (i <= j && nums[i] <= v) i++;
            while (i <= j && nums[j] > v) j--;
            // i <= j 以及 j-- 操作在 i++ 之后 可以确保在结束时得到正确的新枢轴 j (j < i)
            if (i < j) {
                int t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
            }
        }
        if (v > nums[j]) {
            nums[lo] = nums[j];
            nums[j] = v;
        }
        return j;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
