#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    stack<char> st;
    int flag = 1;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (st.empty()) {flag = 0; break;}
            else if (s[i] == ')' && st.top() == '(') st.pop();
            else if (s[i] == ']' && st.top() == '[') st.pop();
            else if (s[i] == '}' && st.top() == '{') st.pop();
            else {flag = 0; break;}
        } 
    }
    if (!st.empty()) flag = 0;
    if (flag) cout << "right";
    else cout << "wrong";
    return 0;
}