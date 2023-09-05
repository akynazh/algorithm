#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, res;
    cin >> s;
    int last_num = 0;
    for (int i = 0; i < s.length(); i++) {
        int flag = 0;
        stack<int> st_num;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            st_num.push(s[i++] - '0');
            flag = 1;
        }
        if (!flag) {
            while (last_num--) {
                res += s[i];
            }
            last_num = 0;
        } else {
            i--;
            int k = 1;
            while (!st_num.empty()) {
                last_num += st_num.top() * k;
                k *= 10;
                st_num.pop();
            }
        }
    }
    cout << res;
    return 0;
}
