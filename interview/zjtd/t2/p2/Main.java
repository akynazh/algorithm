package interview.zjtd.t2.p2;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

/**
 * @Author jiangzhh
 * @Description:
 * @Date: Create in 19:13 2023/8/20
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        AtomicLong point = new AtomicLong();
        PriorityQueue<Card> cards = new PriorityQueue<>(Comparator.comparingInt(c -> c.num));
        for (int i = 0; i < n; i++) {
            cards.add(new Card(sc.nextInt(), sc.nextInt(), sc.next()));
        }
        Map<String, List<Card>> cardMap = new HashMap<>();
        while (!cards.isEmpty()) {
            Card card = cards.poll();
            List<Card> lst = cardMap.getOrDefault(card.color, new ArrayList<>());
            lst.add(card);
            cardMap.put(card.color, lst);
        }
        cardMap.forEach((color, lst) -> {
            if (lst.size() < 5) return;
            for (int i = 0; i < lst.size() && i + 4 < lst.size(); i++) {
                Card card1 = lst.get(i);
                Card card2 = lst.get(i + 1);
                Card card3 = lst.get(i + 2);
                Card card4 = lst.get(i + 3);
                Card card5 = lst.get(i + 4);
                // 优化
                // 首先获取 card1~card5  得到 .num.min 减去最小值后继续
                while (true) {
                    if (card1.count != 0 && card2.count != 0 && card3.count != 0 && card4.count != 0 && card5.count != 0
                            && card1.num + 1 == card2.num && card2.num + 1 == card3.num
                            && card3.num + 1 == card4.num && card4.num + 1 == card5.num) {
                        point.getAndIncrement();
                        card1.count--;
                        card2.count--;
                        card3.count--;
                        card4.count--;
                        card5.count--;
                    } else {
                        break;
                    }
                }
            }
        });
        System.out.println(point);
    }
}

// 优化
// 同花色下同值
// class Node {
//     Set<Integer> numSet;
//     Map<Integer, Long> numCount;
// }
class Card {
    int num;
    int count;
    String color;

    Card(int a, int b, String c) {
        num = a;
        count = b;
        color = c;
    }
}