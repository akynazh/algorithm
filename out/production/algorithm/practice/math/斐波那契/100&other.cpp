#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
 
LL llmul( LL a,LL b,LL mod ) {
	a%=mod;a+=mod;a%=mod;
	b%=mod;b+=mod;b%=mod;
	if ( a<b )	swap( a,b );
	LL ret=0;
	while ( b ) {
		if ( b&1 )ret=( ret+a )%mod;
		a=( a<<1 )%mod;
		b/=2;
	}
	return ret;
}
struct matrix {
    LL x[3][3];
    matrix() {memset( x,0,sizeof x );}
};
matrix mmul( matrix &A,matrix &B,LL mod ) {
    matrix ret;
    for ( int i=1; i<=2; i++ )
		for ( int j=1; j<=2; j++ )
			for ( int k=1; k<=2; k++ )
        	ret.x[i][j]=( ret.x[i][j]+llmul( A.x[i][k],B.x[k][j],mod ) )%mod;
    return ret;
}
matrix E,A;
LL fib( LL n,LL mod ) {
    matrix O=E,B=A;
    while ( n ) {
        if ( n&1 )O=mmul( O,B,mod );
        B=mmul( B,B,mod );
        n/=2;
    }
    return O.x[1][2];
}
LL solve( LL n,LL m,LL mod ) {
    //f(n)%f(m)%mod
    LL t=n/m;
    //(f(m-1)^t*f(n%m))%f(m)%mod;
    //f(i)^2%f(i-1)=(-1)^(i+1)
    LL p=t/2,q=t%2;
    //{f(m-1)^q*(-1)^(pm)*f(n%m)}%f(m)%mod
    LL fuhao=p*m%2==0?1:-1;
    if ( q==0 ) {
        LL ans=fib( n%m,mod )*fuhao;
        ans%=mod;
        ans+=mod;
        return ans%mod;
    }
    if ( n%m==0 )return 0;
    //f(m-1)*f(n%m)*fuhao%f(m)%mod
    //x%y%mod=(x-a*y)%mod
    //a=[x/y]
    LL x=(llmul(fib(n%m,mod),fib(m-1,mod),mod)*fuhao%mod+mod)%mod;
    LL y=fib(m,mod);
    LL a=fib(n%m-1,mod);
    if(n%m%2==0)	a--;
    if(fuhao<0)	a++;
    a=(a%mod+mod)%mod;
    return ((x-llmul(a,y,mod))%mod+mod)%mod;
}
 
int main ()
{
    A.x[1][2]=A.x[2][1]=A.x[2][2]=1;
    E.x[1][1]=E.x[2][2]=1;
    LL n,m,mod;
    while ( cin>>n>>m>>mod )
        cout<<( solve( n+2,m,mod )-1+mod )%mod<<endl;
    return 0;
}
