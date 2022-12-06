#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	stack<int> s;
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	cout << s.top() << endl;//14 
	cout << s.size() << endl;//5 
	int x = s.empty();
	cout << x << endl;//0 
	s.pop();
	x = s.empty();
	cout << x << endl;	//0 
	cout << s.top() << endl;//13 
	return 0;
} 
