#include <bits/stdc++.h>
using namespace std;
int n, flag = 0;
int ans[15];
stack<int> st;
queue<int> q;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) q.push(i+1);
    for (int i = 0; i < n; i++) cin >> ans[i];
    int idx = 0;
    while (!q.empty()) {
        st.push(q.front()); q.pop();
        while (!st.empty() && st.top() == ans[idx]) {
            idx++;
            st.pop();
        }
    }
    if (idx == n) cout << "yes";
    else cout << "no";
    return 0;
}