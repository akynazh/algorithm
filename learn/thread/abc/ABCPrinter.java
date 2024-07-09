package practice.thread.abc;

import java.util.concurrent.Semaphore;

/**
 * @author jiangzhh
 * @date 2024/7/2
 */
public class ABCPrinter {
    private final int max;
    // 从线程 A 开始执行
    private final Semaphore semaphoreA = new Semaphore(1);
    private final Semaphore semaphoreB = new Semaphore(0);
    private final Semaphore semaphoreC = new Semaphore(0);

    public ABCPrinter(int max) {
        this.max = max;
    }

    public void printA() {
        print("A", semaphoreA, semaphoreB);
    }

    public void printB() {
        print("B", semaphoreB, semaphoreC);
    }

    public void printC() {
        print("C", semaphoreC, semaphoreA);
    }

    private void print(String alphabet, Semaphore currentSemaphore, Semaphore nextSemaphore) {
        for (int i = 1; i <= max; i++) {
            try {
                currentSemaphore.acquire();
                System.out.println(Thread.currentThread().getName() + " : " + alphabet);
                // 传递信号给下一个线程
                nextSemaphore.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }
    }

    public static void main(String[] args) {
        ABCPrinter printer = new ABCPrinter(5);

        Thread threadA = new Thread(printer::printA, "Thread A");
        Thread threadB = new Thread(printer::printB, "Thread B");
        Thread threadC = new Thread(printer::printC, "Thread C");

        threadA.start();
        threadB.start();
        threadC.start();
    }
}
