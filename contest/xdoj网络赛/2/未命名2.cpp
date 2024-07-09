#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int mod = 998244353;
int n;
long long num = 0;
set<int> s1, s2;
int main(){
	cin >> n;
	for(int i = 1; i <= (1 << n-1) - 1; i++){
		s1.clear();
		s2.clear();
		int c1 = 0, c2 = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				c1++;
				s1.insert(j+1);
			}
		}
		for(int j = 1; j <= n; j++){
			if(s1.find(j) == s1.end()){
				c2++;
				s2.insert(j);
			}
		}
		if(s1.find(c1) != s1.end() && s2.find(c2) != s2.end()){
			num++;
			num %= mod;
		}
	}
	cout << num * 2 % mod;
	return 0;
}
