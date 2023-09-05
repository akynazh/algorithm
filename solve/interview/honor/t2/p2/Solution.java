package interview.honor.t2.p2;

import java.util.*;


public class Solution {
    int sum = 0;
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回硬币组合的数量
     * @param coins int整型一维数组 硬币的面值
     * @param limits int整型一维数组 硬币数量的限制
     * @param amount int整型 要凑成的目标金额
     * @return int整型
     */
    public int coinChangeWithLimits (int[] coins, int[] limits, int amount) {
        // write code here
        recurSelect(0, 0, coins, limits, amount);
        return sum;
    }

    private void recurSelect(int idx, int curMoney, int[] coins, int[] limits, int amount) {
        if (idx == coins.length) return;
        int left = limits[idx];
        for (int i = 0; i <= left; i++) {
            if (curMoney + coins[idx] * i == amount) {
                sum++;
                return;
            }
            limits[idx] -= i;
            recurSelect(idx + 1, curMoney + coins[idx] * i, coins, limits, amount);
            limits[idx] += i;
        }
    }
}