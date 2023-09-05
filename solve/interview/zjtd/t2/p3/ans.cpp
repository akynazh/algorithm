/*
小红定义一个数组是好数组，当且仅当该数组中有且仅有一个元素和其他元素不同，剩余的所有元素相同。

例如，[2,2,2,5,2,2]是好数组。

小红拿到了一个数组，她可以进行若干次操作，每次操作可以使得一个元素加1或者减1。小红希望用尽可能少的操作次数使得该数组变成好数组，你能帮帮她吗?
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
long long ans, t;
void sol(int idx, vector<int>& a)
{
 if (idx < 0 || idx >= n) return;
 int aim = a[idx];
 t = 0;
 int mx = 0;
 for (int g : a)
 {
  mx = max(mx, abs(g - aim));
  t += abs(g - aim);
 }
 ans = min(ans, t - mx);
}
int main()
{
 cin >> n;
 vector<int> a(n);
 for (int& g : a)
 {
  cin >> g;
  ans+=g;
 }
 sort(a.begin(), a.end());
 if (a[0] == a.back())
 {
  ans = 1;
 }
 else
 {
 // 中位数，中位数左1，中位数右1
  sol(n / 2, a);
  sol(n / 2 - 1, a);
  sol(n / 2 + 1, a);
 }
 cout << ans << endl;
}