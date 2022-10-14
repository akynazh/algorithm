#include <bits/stdc++.h>
using namespace std;
int n;
int tree[1024 + 10], tree1[1024 + 10];
int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) break;
        string str;
        cin >> str;
        memset(tree, -1, sizeof(tree));
        for (int i = 0; i < str.length(); i++) {
            int k = 1, val = str[i] - '0';
            while (tree[k] != -1) {
                if (tree[k] > val) k = k * 2;
                else k = k * 2 + 1;
            }
            tree[k] = val;
        }
        for (int i = 0; i < n; i++) {
            cin >> str;
            int flag = 1;
            memset(tree1, -1, sizeof(tree1));
            for (int i = 0; i < str.length(); i++) {
                int k = 1, val = str[i] - '0';
                while (tree1[k] != -1) {
                    if (tree1[k] > val) k = k * 2;
                    else k = k * 2 + 1;
                }
                tree1[k] = val;
                if (tree1[k] != tree[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}