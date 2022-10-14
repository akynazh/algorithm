#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	string s1(12, 'i');
	cout << s1 << endl;//iiiiiiiiiiii 
	string s2(s1);
	cout << s2 << endl;//iiiiiiiiiiii 
	string s3("iloveyou");
	cout << s3 << endl;//iloveyou
	string s4 = s3;
	cout << s4 << endl;//iloveyou 
	s4 += "forever";
	cout << s4 << endl;//iloveyouforever 
	int pos = s4.find("o"); 
	cout << pos << endl;//2 
	pos = s4.rfind("o");
	cout << pos << endl;//9 
	pos = s4.find("o", 5);
	cout << pos << endl;//6 
	string s5 = "abcdavedabc";
	s5.replace(1,5,"x");//这里是char类型 ，必须为”“ 
	cout << s5 << endl;//axedabc 
	string s6 = "abcd";
	string s7("abc");
	int cmp = s6.compare(s7);
	cout << cmp << endl;//1 
	s7+="d";
	cmp = s7.compare(s6);
	cout << cmp << endl;//0 
	s7.insert(1,2,'x');//这里是char*类型，指定为单个字符必须为'' 
	cout << s7 << endl;//axxbcd 
	s7.erase(1,2);
	cout << s7 << endl;//abcd 
	string s8 = s7.substr(1,3);
	cout << s8 << endl;//bcd 
	reverse(s8.begin(), s8.end()); 
	cout << s8 << endl;//dcb 
	return 0;
}
