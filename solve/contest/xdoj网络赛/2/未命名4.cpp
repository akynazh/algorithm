#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#pragma GCC optimize(2)
using namespace std;
const int mod = 998244353;
int n, num = 0;
map<int, int> m;
void countNum(int a, int b){
	int c = min(b, a-b), t = 1;
	for(int i = a, j = c; j > 0; i--, j--)	t *= i;
	for(int i = c; i >= 2; i--)	t /= i;
	t *= 2;
	t %= mod;
	num %= mod;
	num += t;
	num %= mod;
	return;
}
inline void getNum(int sum, int left, int s){
	if(sum * 2 == n)	return;
	if(left == 0){
		if(m[sum] == 0 && m[n-sum] ==1){
			num += 2;
			num %= mod;
		}
		return;	
	}
	for(int i = s; i <= n; i++){
		if(i == sum)	continue;
		if(m[n-sum] == 0 && i > n-sum)	return;
		m[i] = 1;
		if(m[n-sum] == 1 && i > sum){
			countNum(n - i, left-1);
			m[i] = 0;
			return;
		}
		getNum(sum, left-1, i+1);
		m[i] = 0;
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)	m[i] = 0;
	for(int i = 1; i <= n/2; i++)	getNum(i, i, 1);
	cout << num % mod;
	return 0;
}
