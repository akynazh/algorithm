#include<stdio.h>
long long n, mod, sum = 0;
struct Matrix{
	long long mat[3][3];
};

Matrix Mul(Matrix m, Matrix m_f, int t){//矩阵乘法 m*(m_f或m) 
	Matrix M;
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			M.mat[i][j] = 0;
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= t; j++)//t==1时得m_f, t==2时得m 
			for(int k = 1; k <= 2; k++){
				M.mat[i][j] += (m.mat[i][k] % mod) * (m_f.mat[k][j] % mod);
				M.mat[i][j] %= mod;
			}
	return M;
}

long long Pow_Mod(long long num){//矩阵快速幂 
	Matrix m, m_f;
	m.mat[1][1] = m.mat[1][2] = m.mat[2][1] = 1; m.mat[2][2] = 0;
	m_f.mat[1][1] = m_f.mat[2][1] = 1;
	while(num){
		if(num & 1)	m_f = Mul(m, m_f, 1);
		num >>= 1;
		m = Mul(m, m, 2);
	}
	return m_f.mat[1][1];
}

int main(){
	scanf("%lld%lld", &n, &mod);
	sum = Pow_Mod(n) - 1;//f(1)+...+f(n) == f(n+2)-1
	printf("%lld", sum % mod);
	return 0;
}
