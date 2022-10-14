#include <bits/stdc++.h>
using namespace std;
struct person {
    int num;
    person(int a) {
        num = a;
    }
};
int main() {
    int N, sum, flag = 0;
    cin >> N;
    sum = N;
    queue<person> q;
    for (int i = 0; i < N; i++) q.push(person(i+1));
    // 使用队列，每次操作时对队列中元素进行判断，不需要舍弃的就重新加入队列；
    while (sum > 3) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            if (!flag) {
                if ((i+1) % 2 == 0) {
                    q.pop();
                    sum--;
                }
                else {
                    person p = q.front();
                    q.pop();
                    q.push(p);
                }
            } else {
                if ((i+1) % 3 == 0) {
                    q.pop();
                    sum--;
                }
                else {
                    person p = q.front();
                    q.pop();
                    q.push(p);
                }
            }
        }
        flag = !flag;
    }
    while (!q.empty()) {
        printf("%d ", q.front().num);
        q.pop();
    }
    return 0;
}