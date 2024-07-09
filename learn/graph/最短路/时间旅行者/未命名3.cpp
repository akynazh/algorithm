
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<string>
    #include<climits>
    #include<cmath>
    #include<map>
    #include<set>
     
    using namespace std;
     
     
    int main()
    {
    	int m, n;
     
    	while (cin >> n >> m) {
     
    		vector<int> dp(n + 1, INT_MAX);	//从城市1到其他城市的最短距离
    		dp[1] = 0;
     
    		vector<vector<int> > city(n + 1, vector<int>(n + 1, 0));
     
    		for (int i = 0; i < m; i++) {
     
    			int a, b, t;
    			cin >> a >> b >> t;
     
    			city[a][b] = t;
    		}
     
     
    		for (int i = 1; i <= n; i++) {
     
    			for (int j = 1; j <= n; j++) {
     
    				if (city[i][j] != 0) {
     
    					dp[j] = min(dp[j], dp[i] + city[i][j]);
    				}
    			}
    		}
     
    		int flag = 0;
    		for (int i = 1; i <= n; i++) {
     
    			for (int j = 1; j <= n; j++) {
     
    				if (city[i][j] != 0) {
     
    					if (dp[i] + city[i][j] < dp[j]) {
     
    						flag = 1;
    						break;	//存在负权回路
    					}
    				}
    			}
    		}
     
    		
    		if(dp[n] < 0 || flag == 1)
    			cout << "YES" << endl;
    		else if(dp[n] >= 0)
    			cout << "NO" << endl;
    	}
    }
     


