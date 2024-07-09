//01�������� 
void solve(){//dp[0][0~W] = 0
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(j < w[i])	dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
		}
	}
} 
//���������������
void solve(){//dp[0][0~s.length] = 0 dp[0~t.length] = 0
	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < t.length(); j++){
			if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
} 
//������Ӵ�����
void solve(){//dp[0][0~s.length] = 0 dp[0~t.length] = 0
	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < t.length(); j++){
			if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = 0;
		}
	}
} 
//��ȫ��������
void solve(){//dp[0][0~W] = 0
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(j < w[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]]+v[i]);
		}
	}
} 
//ʹ�ù��������ʡ�ռ�
//dp[2][MAX_W+1]
//dp[i+1]ֻ��Ҫdp[i]��dp[i+1] 
//nż,n&1==0;n��,n&1==1 
void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(j < w[i]) dp[i&1][j] = dp[(i-1)&1][j];
			else dp[i&1][j] = max(dp[(i-1)&1][j], dp[(i-1)&1][j-w[i]]+v[i]);
		}
	}
}
//01��������֮2
//����Wת��ΪV dp[MAX_N +1][MAX_N*MAX_V+1] 
void solve(){//dp[0][0]=0 �����ʼ��ΪINF 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= MAX_N*MAX_V; j++){
			if(j < v[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
		} 
	}
}
for(int i = 0; i <= MAX_N*MAX_V; i++) if(dp[n][i] <= W) res = i;
//���ز��ֺ����� 
//dp[MAX_K+1]
void solve(){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= K; j++){
			if(dp[j] >= 0) dp[j] = m[i];//������������ܸ���
			else if(j < a[i] || dp[j-a[i]] <= 0) dp[j] = -1;
			//dp[j-a[i]]������0��֤���������ֻ���ʣ 
			else dp[j] = dp[j-a[i]]-1;
			//�������ֵĸ�����һ 
		}
	}
}
//���������������
//�ⷨһ
//���ƹ�ϵdp[i]=max{1,dp[j]+1}(j<i��aj<ai)
void solve(){
	int res = 0;
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++)	
			if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
		res = max(res, dp[i]);	
	}
}
//�ⷨ��
//����STL��lower_bound,�ҳ�dp�е�һ��>=a[i]��λ�ã�����ָ�룩
void solve(){
	fill(dp, dp+n, INF);
	for(int i = 0; i < n; i++)
		*lower_bound(dp, dp+n, a[i]) = a[i];
} 
//�йؼ��������dp
//dp[MAX_M+1][MAX_N+1]
void solve(){
	dp[0][0] = 1;//��������ʼ��Ϊ0 
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(j >= i) dp[i][j] = dp[i-1][j] + dp[i][j-i];
			else dp[i][j] = dp[i-1][j]; 
		}
	}
}













