/*
小红定义一个字符串的权值为:极长“连续段”的数量。所谓极长“连续段”，指尽可能长的一段字符全部相同的连续子串。例如,"1100111"共有3个连续段:"11"、"00”和"111”，所以权值为 3。

现在小红拿到了一个01串，小红希望你帮她求出所有子串的权值之和。

*/
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
 int n;
 scanf("%d", &n);
 char s[200020];
 scanf("%s", s + 1);
 long long ans = 0;
 for (int i = 2; i <= n; i++) if (s[i] != s[i - 1]) ans += 1ll * (i - 1) * (n - (i - 1));
 printf("%lld\n", ans + 1ll * n * (n + 1) / 2);
}