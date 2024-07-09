#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
bool cmp(string s1, string s2) {
    return s1.length() < s2.length();
}

int main() {
    int N, maxc[MAX_N], fee[MAX_N];
    vector<string> cho;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        cho.push_back(s);
    }
    sort(cho.begin(), cho.end(), cmp);

    return 0;
}