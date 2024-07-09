#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
struct node {
    int pos, val, next;
    node (int a, int b, int c) {
        pos = a; val = b; next = c;
    }
};
int main() {
    int start, n, count = 0;
    int m[10000 + 10];
    memset(m, 0, sizeof(m));
    vector<node> v;
    scanf("%d%d", &start, &n);

    int a, b, c, sa, sb;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (!m[abs(b)]) {
            count ++;
            m[abs(b)] = 1;
        }
        if (a == start) {
            sa = a; sb = b;
            start = c;
        }
        v.push_back(node(a, b, c));
    }
    printf("%d\n", count);
    // 先对头节点进行输出方便后面操作
    printf("%05d %d ", sa, sb);
    m[abs(sb)] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j].pos == start) {
                if (m[abs(v[j].val)]) { // 若值的绝对值未被访问过
                    printf("%05d\n", start);
                    printf("%05d %d ", v[j].pos, v[j].val);
                    m[abs(v[j].val)] = 0; 
                }
                start = v[j].next;
                break;
            }
        }
    }
    printf("-1");
    return 0;
}