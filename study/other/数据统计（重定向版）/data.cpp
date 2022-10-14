#define LOCAL  //本机测试时使用重定向方式读写文件，若比赛要求标准输入输出只需提交前删除#define LOCAL 
#include<stdio.h> 
#define INF 1000000000
int main()
{
	//重定向部分 
#ifdef LOCAL
	// freopen()函数用于文件流的的重定向，一般是将 stdin、stdout 和 stderr 重定向到文件。
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int x, n = 0, min = INF, max = -INF, s = 0;
	while(scanf("%d", &x) == 1){
		s += x;
		if(x < min)	min = x;
		if(x > max)	max = x;
		n++;
	}
	printf("%d %d %.3f\n", min, max, (double)s/n);
	return 0;
}
