#include<stdio.h>//������Ҫ�����ļ������������ֹʹ���ض���
#define INF 1000000000//��������Ҫһ�£����� ͳһ"data" 
int main()
{
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	//������Ϊ��д��׼���������ֻ�踳ֵ��fin=stdin,fout=stdout��
//	fin = stdin;
//	fout = stdout;//������Ϻ�enter��ctrl+Z,enter  // linux ctrl+D 
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
