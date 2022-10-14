// 计算出找序列个数
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, f[20] = {0};
	f[0] = f[1] = 1;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
		for(int j = 0; j <= i-1; j++)
			f[i] += f[j]*f[(i-1)-j];
	printf("%d", f[n]);
	return 0;
}
/*
建立数组f。f[i]表示i个数的全部可能性。
设 x 为当前出栈序列的最后一个，则x有n种取值
由于x是最后一个出栈的，所以可以将已经出栈的数分成两部分
比x小的数有x-1个，所以这些数的全部出栈可能为f[x-1]
比x大的数有n-x个，所以这些数的全部出栈可能为f[n-x]
这两部分互相影响，所以一个x的取值能够得到的所有可能性为f[x-1] * f[n-x]
另外，由于x有n个取值，所以得到卡特兰数ans = f[0]*f[n-1] + f[1]*f[n-2] + ... + f[n-1]*f[0];
*/
