package interview.mi.p1;

import java.util.*;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 16:29 2023/9/2
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int freq = sc.nextInt();
        String data = sc.next();
        String[] dataList = data.split(",");
        int mi = Integer.MAX_VALUE;
        List<Double> lossList = new ArrayList<>();

        for (String v : dataList) {
            int i = v.indexOf(":");
            int f = Integer.valueOf(v.substring(0, i));
            double loss = Double.valueOf(v.substring(i + 1));
            int d = Math.abs(freq - f);
            if (mi > d) {
                mi = d;
                lossList = new ArrayList<>();
                lossList.add(loss);
            } else if (mi == d) {
                lossList.add(loss);
            }
        }
        double res = 0;
        for (double d : lossList) res += d;
        System.out.printf("%.1f", res / lossList.size());
    }
}
