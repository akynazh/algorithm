#include<iostream>
using namespace std; 
int n;
int main(){
	/*
	二进制中每一位的地方代表一个元素的位置 0代表该元素无 1代表有 
	一共n位，就是集合有n个元素  一共2^n - 1个非空子集
	从1到2^n - 1，二进制中每位与1相与，如果为1则代表子集有该元素 
	*/ 
	cin >> n;
	for(int i = 1; i <= (1 << n) - 1; i++){ 
		for(int j = 0; j < n; j++){
			//1右移n-1次就可以到达第n位 
			if(i & (1 << j))	cout << j << " ";
		}
		cout << endl;
	}
	
	// int a[5] = {2, 9, 5, 4, 7};
	// for(int i = 1; i <= (1 << 5) - 1; i++){
	// 	for(int j = 0; j < 5; j++){
	// 		if(i & (1 << j))	cout << a[j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
} 
