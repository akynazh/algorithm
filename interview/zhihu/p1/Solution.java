package interview.zhihu.p1;

public class Solution {
    int sum = 0;
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param salary int整型一维数组 
     * @param subordinate int整型二维数组 
     * @param id int整型 
     * @return int整型
     */
    public int getTotalSalary (int[] salary, int[][] subordinate, int id) {
        solve(salary, subordinate, id);
        return sum;
    }

    private void solve(int[] salary, int[][] subordinate, int id) {
        sum += salary[id - 1];
        for (int subId : subordinate[id - 1]) {
            solve(salary, subordinate, subId);
        }
    }
}