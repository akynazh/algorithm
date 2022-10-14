#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s = "12345";
	if (s.length() > 0) cout << "ok" << endl;

	if (s.length() > -1) cout << "okkk" << endl;
	// str.length()的返回值是unsigned int，如果直接与-1比较的话，比较的过程int会被隐式转化成unsigned int，所以-1会变成很大的数

	if ((int)s.length() > -1) cout << "yes" << endl; 
	// 将s.length() 返回值强制转换为int类型即可 一般比较都进行强制转换较为安全哦！

	s += "a";
	cout << s << endl;
	const char* s1 = "abc";
	s = s1;
	cout << s << endl; // abc
	s += "a";
	cout << s << endl; // abca 证明string只是引用了s1
	cout << s1 << endl; // abc
	return 0;
	 
}
