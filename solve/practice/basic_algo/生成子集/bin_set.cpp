#include<iostream>
using namespace std; 
int n;
int main(){
	/*
	��������ÿһλ�ĵط�����һ��Ԫ�ص�λ�� 0�����Ԫ���� 1������ 
	һ��nλ�����Ǽ�����n��Ԫ��  һ��2^n - 1���ǿ��Ӽ�
	��1��2^n - 1����������ÿλ��1���룬���Ϊ1������Ӽ��и�Ԫ�� 
	*/ 
	cin >> n;
	for(int i = 1; i <= (1 << n) - 1; i++){ 
		for(int j = 0; j < n; j++){
			//1����n-1�ξͿ��Ե����nλ 
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
