#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Matrix{
	int a, b;
	Matrix(int v1, int v2) {a = v1; b = v2;}
	Matrix() {}
}; 

int main()
{
	Matrix m[26];
	stack<Matrix> s;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string st;
		cin >> st;
		int k = st[0] - 'A';
		cin >> m[k].a >> m[k].b;
	}
	string sec;
	while(cin >> sec){
		int sum = 0;
		bool flag = true; 
		for(int i = 0; i < (int)(sec.length()); i++){
			if(isalpha(sec[i]))	s.push(m[sec[i] - 'A']);
			else if(sec[i] == ')'){
				Matrix m2 = s.top();	s.pop();
				Matrix m1 = s.top();	s.pop();
				if(m1.b != m2.a){flag = false; break;}
				sum += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a, m2.b)); 
			}
		}
		if(flag)	cout << sum << endl;
		else cout << "error" << endl;
	}
	return 0;
}
/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
*/
