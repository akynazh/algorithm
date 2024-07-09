#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int ca = 0, cb = 0, cc = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') ca++;
        else if (s[i] == 'b') cb++;
        else cc++;
    }
    cout << abs(ca - cb - cc) / 2;
    return 0;
}