#include<stdio.h>//若比赛要求用文件输入输出，禁止使用重定向
#define INF 1000000000//比赛名字要一致！！！ 统一"data" 
int main()
{
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	//如果想改为读写标准输入输出，只需赋值“fin=stdin,fout=stdout”
//	fin = stdin;
//	fout = stdout;//输入完毕后enter，ctrl+Z,enter  // linux ctrl+D 
	int x, n = 0, min =INF, max = -INF, s = 0;
	while(fscanf(fin, "%d", &x) == 1){
		s += x;
		if(x < min)	min = x;
		if(x > max)	max = x;
		n++;
	}
	fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);
	fclose(fin);
	fclose(fout);
	return 0;
 } 
