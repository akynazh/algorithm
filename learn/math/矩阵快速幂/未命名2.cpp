#include<cstdio>
//#define LOCAL
using namespace std;
long long n, p;
const int e = 1e9 + 7;
struct Matrix{
	long long mat[110][110];//方阵 
};
Matrix Mul(Matrix m1, Matrix m2){//方阵乘法&取模运算 
	Matrix M;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			M.mat[i][j] = 0; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				M.mat[i][j] += ( (m1.mat[i][k] % e) * (m2.mat[k][j] % e) );
				M.mat[i][j] %= e;
			}
		}
	return M;
}
Matrix Pow_Mod(Matrix m){//矩阵快速幂 
	Matrix M;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			if(i == j) M.mat[i][j] = 1;
			else M.mat[i][j] = 0;
		}//单位阵 
	while(p){
		if(p & 1)	M = Mul(M, m);
		p >>= 1;
		m = Mul(m, m);
	}
	return M;
}
int main(){
#ifdef LOCAL
	freopen("zh.in", "r", stdin);
	freopen("zh.out", "w", stdout);
#endif
	scanf("%lld%lld", &n, &p);
	Matrix m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%lld", &m.mat[i][j]);
	m = Pow_Mod(m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%lld ", m.mat[i][j]);
		printf("\n");
	}
	return 0;
}
