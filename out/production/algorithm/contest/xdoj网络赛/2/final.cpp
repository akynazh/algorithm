#include<iostream>
#include<cstdio>
using namespace std;
const int mod = 998244353;
const int maxn = 1e5 + 10;
typedef long long LL;
LL n, num = 0;
LL a[maxn], f[maxn];
LL Pow(LL a, LL b){
	LL t = 1;
	while(b){
		if(b & 1)	t = t * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return t;
}
void Init(){
	a[0] = a[1] = 1;
	f[0] = f[1] = 1;
	for(LL i = 1; i < maxn; i++){
		f[i] = f[i-1] * i % mod;
		a[i] = a[i-1] * Pow(i, mod-2) % mod;
	}
}
LL C(LL n, LL m){
	if(n < 0 || m < 0 || n < m)	return 0;
	return f[n] * a[n-m] % mod * a[m] % mod;
}
void getNum(LL sum){
	if(sum * 2 == n)	return;
	num += C(n-2, sum-1) * 2 % mod;
	num %= mod;
	return;
}
int main(){
	Init();
	cin >> n;
	for(LL i = 1; i <= n/2; i++)	getNum(i);
	cout << num;
	return 0;
}
