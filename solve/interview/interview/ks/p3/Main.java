package interview.interview.ks.p3;


import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:51 2023/9/8
 */
class Point {
    Double x;
    Double y;
    Point(Double a, Double b) {
        x = a;
        y = b;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            points.add(new Point(sc.nextDouble(), sc.nextDouble()));
        }
        double s = sc.nextDouble();
        double left = s;
        double lastPointX = points.get(0).x, lastPointY = points.get(0).y;
        System.out.printf("%.5f, %.5f\n", lastPointX, lastPointY);
        for (int i = 1; i < n; i++) {
            // 当前边信息
            double lenX = points.get(i).x- points.get(i - 1).x;
            double lenY = points.get(i).y - points.get(i - 1).y;
            double lenZ = Math.sqrt(lenX * lenX + lenY * lenY);
            // 一开始到下一点的距离
            double toNextPointDis = lenZ;
            // 走上次剩余的
            if (toNextPointDis >= left) {
                toNextPointDis -= left;
                lastPointX += lenX * left / lenZ;
                lastPointY += lenY * left / lenZ;
                System.out.printf("%.5f, %.5f\n", lastPointX, lastPointY);
            }
            // 在当前边上走
            while (toNextPointDis >= s) {
                toNextPointDis -= s;
                lastPointX += lenX * s / lenZ;
                lastPointY += lenY * s / lenZ;
                System.out.printf("%.5f, %.5f\n", lastPointX, lastPointY);
            }
            left = left - toNextPointDis;
        }
    }
}
