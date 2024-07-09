#include<iostream>
using namespace std;
int main(){
	int f[6][6] = {0};
	f[1][0] = 2; f[2][0] = 1; f[3][0] = 4; f[4][0] = 5; f[5][0] = 6;
	for(int j = 1; j <= 5; j++){
		for(int i = 1; i <= 5; i++){
			if(i + (1 << j) - 1 <= 5){
				f[i][j] = max(f[i][j-1], f[i + 1 << (j-1)][j-1]);
			}
		}
	}
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
} 
