#include <bits/stdc++.h>
using namespace std;
int m, p;
int table[100+10];
int key_find(int k, int& pos) {
    int s = k % p;
    for (int i = 0; i < m; i++) { // 线性探测再散列
        pos = (s + i) % m;
        if (table[pos] == k) return 1; // find the key
        else if (table[pos] == -1) return -1; // key not exist
    }
    return -1;
}



int main() {
    memset(table, -1, sizeof(table));
    int num = 0, key;
    scanf("%d%d", &m, &p);
    for (;;) {
        scanf("%d", &key);
        if (key == -1) break;
        int pos;
        int t = key_find(key, pos);
        if (t == -1) { // key not exist
            if (num == m-1) { // full
                printf("Table full");
                break;
            }
            table[pos] = key; // insert
            printf("%d\n", pos);
            num++;
        }
        else printf("%d\n", pos);
    }
    return 0;
}