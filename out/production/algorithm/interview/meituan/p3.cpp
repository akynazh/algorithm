#include <bits/stdc++.h>
using namespace std;

bool is_hui(string s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}
string get_hui(string s) {
    int c = 0;
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != s[j]) {
            if (s[i] == 'a' || s[j] == 'a') {
                s[i] = s[j] = 'a';
                c++;
            } else {
                string s1 = s;
                s1[i] = s1[j] = 'a';
                if (is_hui(s1)) return s1;
                else {
                    char t = s[i] >= s[j] ? s[j] : s[i];
                    s[i] = s[j] = t;
                    c++;
                }
            }
        }
    return s;
}
string get_smallest(string s) {
    int c = 0;
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != 'a') {
            s[i] = s[j] = 'a';
            c++;
            if (c == 2) break;
        }
    return s;
}
int main() {
    string s;
    cin >> s;
    if (!is_hui(s)) {
        cout << get_hui(s);
    } else {
        cout << get_smallest(s);
    }
    return 0;
}
