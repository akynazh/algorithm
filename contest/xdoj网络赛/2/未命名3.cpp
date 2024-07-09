#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#pragma GCC optimize(2)
using namespace std;
const int mod = 998244353;
int n, num = 0;
set<int> s1, s2;
void countNum(int a, int b){
	int c = min(b, a-b), t = 1;
	for(int i = a, j = c; j > 0; i--, j--)	t *= i;
	for(int i = c; i >= 2; i--)	t /= i;
	num += t * 2;
	num %= mod;
	return;
}
inline void getNum(int sum, int left, int s){
	if(left == 0){
		if(s1.find(sum) == s1.end() && s1.find(n-sum) != s1.end()){
			num += 2;
			num %= mod;
		}
		return;	
	}
	for(int i = s; i <= n; i++){
		if(i == sum)	continue;
		if(s1.find(n-sum) == s1.end() && i > n-sum)	return;
		if(s1.find(sum) != s1.end())	return;
		s1.insert(i);
		if(s1.find(n-sum) != s1.end() && i > sum){
			countNum(sum-i, left-1);
			s1.erase(i);
			continue;
		}
		getNum(sum, left-1, i+1);
		s1.erase(i);
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n/2; i++)	getNum(i, i, 1);
	cout << num % mod;
	return 0;
}
