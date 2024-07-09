package interview.tyy.p2;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 20:28 2023/9/14
 */
import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param h int整型 怪物的血量
     * @return int整型
     */
    public int count (int h) {
        // write code here
        int res = 0;
        int s = 0;
        boolean canJump = true;
        while (s < h) {
            if (canJump) s += 3;
            else s += 1;
            res++;
            canJump = !canJump;
        }
        return res;
    }
}