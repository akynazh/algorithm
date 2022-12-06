#include <bits/stdc++.h>
using namespace std;
int main() {
    // char ~ string
    const char *s1 = "123";
    string str1 = s1; // 若要这样赋值s1必须加const
    cout << str1 << endl; // 123

    char s2[] = "234";
    string str2 = s2;
    cout << str2 << endl; // 234

    const char* s1_1 = str1.c_str(); // // c_str 转 const char*
    cout << s1_1 << endl; // 123


    // char ~ int
    int v1 = atoi(s1);
    cout << v1 << endl; // 123
    v1 += 1;
    char str11[100]; 
    itoa(v1, str11, 10); // 10代表十进制
    cout << str11 << endl; // 124
    // 下面的会失败
    // const char* str111;
    // itoa(v1, str111, 10); // 失败

    // string ~ int
    int val = 223;
    string str3 = to_string(val); // C++11新特性 只适用于string (char[]和char*不可以)
    cout << str3 << endl; // 223
    val = stoi(str3, 0, 10); // 0为起始位置 10即十进制
    cout << val << endl; // 223
}