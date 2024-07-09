#include<iostream>
#include<string>
#include<cmath> 

using namespace std;

int dp[201][40000]; 

int main()
{
	int n, w[201], sum = 0;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
		sum += w[i];
	}
	int bagW = sum/2;
	for(int i = 1; i <= n; i++){
		if(w[i] > bagW){ 
			cout << w[i]-(sum-w[i]) << endl;
			break;
		}
		else{
			for(int j = 1; j <= bagW; j++){
				if(w[i] > j)	dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j],w[i]+dp[i-1][j-w[i]]);
			}
		}
	}
	cout << abs(dp[n][bagW]-(sum-dp[n][bagW])) << endl;
	
	return 0;	
}
