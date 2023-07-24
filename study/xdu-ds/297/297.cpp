#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 1; i <= len; i++) {
        if (i <= len / 2) {
            string s1 = s.substr(0, i);
            int flag = 1;
            for (int j = 0; j + i <= len; j += i) {
                string s2 = s.substr(j, i);
                if (s2 != s1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                printf("%d", i);
                break;
            }
        } else {
            printf("%d", len);
            break;
        }
    }
}