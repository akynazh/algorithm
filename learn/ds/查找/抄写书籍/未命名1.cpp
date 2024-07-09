#include<stdio.h>
#include<string.h> 
int t;
int m, k;
int b[510];
bool divTag[510];
/*
wrong answer
对数据
5 4
100 100 100 100 100

my answer:
100 / 100 100 / 100 100
true answer:
100 / 100 / 100 / 100 100

分析：
if test == 250 num == 3 < 4 CanDiv == true
but if test == 250/2 num == 5 > 4 CanDiv == false
so we get the wrong answer

so when the left book == k - num, we need to stop div process
because we can never div the books since the books == needed pile 
*/
bool CanDiv(long long x){
	int num = 1;
	long long page = 0;
	for(int i = m - 1; i >= 0; i--){
		if(b[i] + page > x){
			page = b[i];
			num++;
		}else	page += b[i];
	}
	return num <= k;
}
void PrintAns(long long x){
	int num = 1;
	long long page = 0;
	memset(divTag, false, sizeof(divTag));
	for(int i = m - 1; i >= 0; i--){
		if(b[i] + page > x){
			page = b[i];
			divTag[i] = true;
		}else	page += b[i];
	}
	for(int i = 0; i < m; i++){
		printf("%d ", b[i]);
		if(divTag[i] == true)	printf("/ ");
	}
	printf("\n");
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &k);
		long long low = 10000000, high = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &b[i]);
			high += b[i];
			if(b[i] < low)	low = b[i];
		}
		while(low <= high){
			long long mid = (low + high) / 2;
			if(CanDiv(mid))	high = mid - 1;
			else low = mid + 1;
		}
		PrintAns(low);
	}
	return 0;
} 
