#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    string s;
    while (cin >> s) v.push_back(s);
    stack<string> st;
    // + * + 42 8 - 36 6 / 9 3
    for (int i = (int)v.size()-1; i >= 0; i--) {
        if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            int a = atoi(s1.c_str());
            int b = atoi(s2.c_str());
            int ans;
            if (v[i] == "+") ans = a + b;
            else if (v[i] == "-") ans = a - b;
            else if (v[i] == "*") ans = a * b;
            else ans = a / b;
            char str[100];
            itoa(ans, str, 10);
            st.push(str);
            if (i == 0) cout << ans;
        } else st.push(v[i]);
    }
    return 0;
}