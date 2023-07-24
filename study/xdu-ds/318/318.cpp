#include <bits/stdc++.h>
using namespace std;

void get_post (string s1, string s2) {
    int root = s2.find(s1[0]);
    string s2_left = s2.substr(0, root);
    string s2_right;
    if (root != s2.length() - 1) s2_right = s2.substr(root+1);
    string s1_left, s1_right;
    if (s2_left.length() > 0) {
        s1_left = s1.substr(1, (int)s2_left.length());
        get_post(s1_left, s2_left);
    }
    if (s2_right.length() > 0) {
        s1_right = s1.substr(s1.length() - s2_right.length());
        get_post(s1_right, s2_right);
    }
    printf("%c", s1[0]);
}
int main() {
    string pre, in;
    cin >> pre >> in;
    get_post (pre, in);
    return 0;
}