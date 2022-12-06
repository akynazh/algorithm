#include<iostream>
#include<algorithm> 
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int a[3] = {1, 2, 3};
	//���ֵ�����������
	//��Ҫ��n�����У���sort 
	while(next_permutation(a, a+3)){
		for(int i = 0; i < 3; i++)	cout << a[i] << " ";
		cout << endl;
	}
	//���� 1 2 3 
	/*
	1 3 2
	2 1 3
	2 3 1
	3 1 2
	3 2 1
	*/
	cout << endl;
	sort(a, a+3, cmp);
	while(prev_permutation(a, a+3)){
		for(int i = 0; i < 3; i++)	cout << a[i] << " ";
		cout << endl;
	}
	//����3 2 1 
	/*
	3 1 2
	2 3 1
	2 1 3
	1 3 2
	1 2 3
	*/ 
	cout << endl; 
	string s = "abc"; 
	while(next_permutation(s.begin(), s.end())){
		for(int i = 0; i < 3; i++)	cout << s[i] << " ";
		cout << endl;
	}
	return 100;
}
