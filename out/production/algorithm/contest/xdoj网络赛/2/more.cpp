#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#define LL long long
#define maxn 1000000
 
using namespace std;
 
const int MOD = 998244353;
 
LL fact[maxn+5];	//�׳� 
LL a[maxn+10];	// �˷���Ԫ 
//LL inv[maxn+10];	//������ 
 
LL pow(LL x)
{
	LL n = MOD-2;
    LL res=1;
	while(n>0)
	{
	   if(n%2==1)	
	   	 res=res*x%MOD;
	   x=x*x%MOD;
	   n>>=1;
	}
	return res;	
}
 
void init(){
    a[0] = a[1] = 1;
    fact[0] = fact[1] = 1;
//  inv[1] = 1;
    for(int i = 2; i <= 1000005; i++)
    {
        fact[i] = fact[i-1] * i % MOD;
		a[i] = a[i-1] * pow(i) % MOD;	//m!��MOD�η� = (m-1)!��MOD�η� * m��MOD�η� 
//      inv[i] = (MOD - MOD/i)*inv[MOD%i]%MOD;
//      a[i] = a[i-1] * inv[i] % MOD;	
    }
}
 
LL C(int n, int m){	//�˷���Ԫ 
	if(n<0||m<0||n<m)return 0;
    return fact[n]*a[n-m]%MOD*a[m]%MOD;
}
 
int main()
{
	int T,n,m;
	LL ans;
	init();//Ԥ���� 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans = C(n,m)%MOD;
		printf("%lld\n",ans);
	} 
	return 0;
}
