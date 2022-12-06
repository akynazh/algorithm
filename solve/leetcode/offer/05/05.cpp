#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        return regex_replace(s, regex(" "), "%20");
    }
};
int main() {
    string s;
    getline(cin, s);
    cout << s << endl;
    Solution solution;
    s = solution.replaceSpace(s);
    cout << s << endl;
    return 0;
}