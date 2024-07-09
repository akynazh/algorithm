#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;

ll quickpower(ll b,ll p)
{
	ll result=1;
	while(p){
		if(p&1){
			result=result*b%mod;
		}
		p>>=1;
		b=b*b%mod;
	}
	return result;
}

ll C(ll n,ll m)
{
	if(n<m){
		return 0;
	}
	ll a=1,b=1;
	for(int i=0;i<m;i++){
		a=a*(n-i)%mod;
		b=b*(i+1)%mod;
	}
	return a*quickpower(b,mod-2)%mod;
}

ll lucas(ll n,ll m)
{
	if(m==0){
		return 1;
	}
	return lucas(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}

int main()
{
	int t;
	ll n,m;
	cin>>t;
	while(t--){
		cin>>n>>m>>mod;
		cout<<lucas(n,m)<<endl;
	}
	return 0;
}

