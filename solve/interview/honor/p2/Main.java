package interview.honor.p2;

import java.util.*;

/**
 * @author akyna
 * @date 04/27 027 6:33 PM
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Info> infos = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();
        String a;
        int val = 1;
        int b, c;
        for (;;) {
            if (!sc.hasNext()) break;
            a = sc.next();
            b = sc.nextInt();
            c= sc.nextInt();
            Info info = new Info(a, b, c);
            infos.add(info);
            m.putIfAbsent(info.fruit, val++);
        }
        Collections.sort(infos, (o1, o2) -> {
            if (!o1.fruit.equals(o2.fruit)) return m.get(o1.fruit) - m.get(o2.fruit);
            if (!o1.weight.equals(o2.weight)) return o1.weight - o2.weight;
            return o1.id - o2.id;
        });
        for (Info info : infos) {
            System.out.println(info.fruit + " " + info.id + " " +  info.weight);
        }
    }
}

class Info {
     String fruit;
     Integer id;
     Integer weight;

    public Info(String fruit, Integer id, Integer weight) {
        this.fruit = fruit;
        this.id = id;
        this.weight = weight;
    }
}