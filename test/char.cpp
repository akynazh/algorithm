#include <bits/stdc++.h>
using namespace std;
void print_str(const char * str) {
    printf("%s\n", str);
}
int main() {
    char s1[] = "abc";
    // "abc"为字符串常量，s1为指针常量，即指针指向常量，指向地址不能改变，指向地址的值可变
    cout << s1 << endl; // abc
    s1[1] = 'd'; // 改变值
    cout << s1 << endl; // adc

    const char* s2 = "abc"; // const是默认存在的
    // "abc"为字符串常量，s2为常量指针，指向地址可变，但指向的地址的值不能变
    cout << s2 << endl; // abc
    s2 = "dfs"; // 改变地址
    cout << s2 << endl; // dfs

    // 因此以上两者皆可用于函数传值
    print_str(s1); // adc
    print_str(s2); // dfs
    return 0;
}