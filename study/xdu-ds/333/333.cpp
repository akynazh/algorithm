#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int num = 1; // 重复字符的起始序号
    map<char, int> mp; // 用于判断字符是否出现过，若出现过则赋予序号进行映射
    char vc1[110]; // 存取某序号字符
    vector<int> vc2[110]; // 存取某字符所有出现位置的下标
    for (int i = 0; i < str.length(); i++) {
        if (!mp[str[i]]) {
            mp[str[i]] = num; 
            vc1[num] = str[i];
            vc2[mp[str[i]]].push_back(i);
            num++;
        } else vc2[mp[str[i]]].push_back(i);
    }
    for (int i = 1; i < num; i++) {
        if (vc2[i].size() > 1) {
            for (int j = 0; j < vc2[i].size(); j++) {
                if (j != vc2[i].size() - 1)
                    printf("%c:%d,", vc1[i], vc2[i][j]);
                else printf("%c:%d\n", vc1[i], vc2[i][j]);
            }
        }
    }
    return 0;
}