#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	int n;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> n;
	cout << n << endl;
	cout << n+1 << endl;
	return 0; 
}
