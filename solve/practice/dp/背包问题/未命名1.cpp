//背包问题
#include<iostream>
#include<algorithm>

using namespace std;

int w[5]={0,2,3,4,5};//每个物品对应的重量 ，其中0是为了整齐和j-w[i]==0时考虑
int v[5]={0,3,4,5,6};//每个物品对应的价值 
int bagW=8;			 //背包最大承载量	
int dp[5][9]={{0}};  //dp[i][j]对前第i件物品，当背包重量为j时的最大价值 
int item[5];		 //最优解情况 

//找出最优解的函数 
void Best(int i, int j) {			
	if (i>=0) {
		if (dp[i][j]==dp[i-1][j]){
			item[i]=0;
			Best(i-1,j);
		}
		else if (j-w[i]>=0&&dp[i][j]==dp[i-1][j-w[i]]+v[i]){ //该判断条件是为了终止递归 
			item[i]=1;
			Best(i-1,j-w[i]);
		}
	}
}
 
int main()
{	
	//绘制动态规划表 
	for(int i=1;i<=4;i++){
		for(int j=1;j<=bagW;j++){
			if(j<w[i])
				dp[i][j]=dp[i-1][j];//装不下第i件物品时 
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);//装得下第i件物品时，取装下后价值 
		}													  //和不装它时的最大价值中 两者的最大值		
	}	

	//输出动态规划表 
	for(int i=0;i<=4;i++){
		for(int j=0;j<=bagW;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}

	//找出最大的dp对应的i&j 
	int max_i=0,max_j=0,max=dp[0][0];
	for(int i=0;i<=4;i++){
		for(int j=0;j<=bagW;j++){
			if(dp[i][j]>max){
				max_i=i;max_j=j;
			}
		}	
	} 

	//找出最优解
	Best(max_i,max_j);

	//输出最优解
	for(int i=1;i<=4;i++)
		cout<<item[i]<<' ';
	cout<<endl;
	 
	return 0;
} 
