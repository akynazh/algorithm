#include<cstdio>
#include<cstring>
#include<iostream> 
int t;
int m, k;
int b[510];
bool divTag[510];

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
	memset(divTag, true, sizeof(divTag));
	//true is ok  1 will not work
	for(int i = m - 1; i >= 0; i--){
		if(k - num == i + 1)	break;
		if(b[i] + page > x){
			num++;
			page = b[i];
		}else{
			page += b[i];
			divTag[i] = false;
		}
	}
	for(int i = 0; i < m-1; i++){
		printf("%d ", b[i]);
		if(divTag[i] == true)	printf("/ ");
	}
	printf("%d\n", b[m-1]);//to avoid redundant space 
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &k);
		long long low = -1, high = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &b[i]);
			high += b[i];
			if(b[i] > low)	low = b[i];//to find the largest pages in one book 
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
