#include <bits/stdc++.h>
using namespace std;
int calculate(char a, char op, char b) {
    int a1 = a - '0', b1 = b - '0', sum;
    switch (op) {
    case '+':
        sum = a1 + b1; break;
    case '-':
        sum = a1 - b1; break;
    case '*':
        sum = a1 * b1; break;
    case '/':
        sum = a1 / b1; break;
    }
    return sum;
}
int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') st.push(s[i]);
        else {
            char a = st.top(); st.pop();
            char b = st.top(); st.pop();
            int ans = calculate(b, s[i], a);
            st.push(ans+'0');
            if (i == s.length()-1) cout << ans;
        }
    }
    
    return 0;
}