//01背包问题 
void solve(){//dp[0][0~W] = 0
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(j < w[i])	dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
		}
	}
} 
//最长公共子序列问题
void solve(){//dp[0][0~s.length] = 0 dp[0~t.length] = 0
	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < t.length(); j++){
			if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
} 
//最长公共子串问题
void solve(){//dp[0][0~s.length] = 0 dp[0~t.length] = 0
	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < t.length(); j++){
			if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = 0;
		}
	}
} 
//完全背包问题
void solve(){//dp[0][0~W] = 0
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(j < w[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]]+v[i]);
		}
	}
} 
//使用滚动数组节省空间
//dp[2][MAX_W+1]
//dp[i+1]只需要dp[i]和dp[i+1] 
//n偶,n&1==0;n奇,n&1==1 
void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(j < w[i]) dp[i&1][j] = dp[(i-1)&1][j];
			else dp[i&1][j] = max(dp[(i-1)&1][j], dp[(i-1)&1][j-w[i]]+v[i]);
		}
	}
}
//01背包问题之2
//这里W转变为V dp[MAX_N +1][MAX_N*MAX_V+1] 
void solve(){//dp[0][0]=0 其余初始化为INF 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= MAX_N*MAX_V; j++){
			if(j < v[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
		} 
	}
}
for(int i = 0; i <= MAX_N*MAX_V; i++) if(dp[n][i] <= W) res = i;
//多重部分和问题 
//dp[MAX_K+1]
void solve(){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= K; j++){
			if(dp[j] >= 0) dp[j] = m[i];//标记这种数字总个数
			else if(j < a[i] || dp[j-a[i]] <= 0) dp[j] = -1;
			//dp[j-a[i]]若大于0，证明这种数字还有剩 
			else dp[j] = dp[j-a[i]]-1;
			//这种数字的个数减一 
		}
	}
}
//最长上升子序列问题
//解法一
//递推关系dp[i]=max{1,dp[j]+1}(j<i且aj<ai)
void solve(){
	int res = 0;
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++)	
			if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
		res = max(res, dp[i]);	
	}
}
//解法二
//利用STL的lower_bound,找出dp中第一个>=a[i]的位置（返回指针）
void solve(){
	fill(dp, dp+n, INF);
	for(int i = 0; i < n; i++)
		*lower_bound(dp, dp+n, a[i]) = a[i];
} 
//有关计数问题的dp
//dp[MAX_M+1][MAX_N+1]
void solve(){
	dp[0][0] = 1;//其他均初始化为0 
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(j >= i) dp[i][j] = dp[i-1][j] + dp[i][j-i];
			else dp[i][j] = dp[i-1][j]; 
		}
	}
}













