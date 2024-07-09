#include<cstdio>
#include<stack>
using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
	while(scanf("%d", &n) == 1){
		if(n == 0)	break;
		while(1){
			scanf("%d", &target[1]);
			if(target[1] == 0){
				printf("\n");
				break;
			}
			int A = 1, B = 1;
			stack<int> s;
			for(int i = 2; i <= n; i++)	scanf("%d", &target[i]);
			int ok = 1;
			while(B <= n){
				if(A == target[B]){
					A++; B++;
				}
				else if(!s.empty() && s.top() == target[B]){
					s.pop(); B++;
				}
				else if(A <= n)	{
					s.push(A); A++;
				}
				else{
					ok = 0;
					break;
				}
			}
		printf("%s\n", ok ? "Yes" : "No");	
		}
	}
	return 0;
} 
