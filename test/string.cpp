#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s = "12345";
	if (s.length() > 0) cout << "ok" << endl;

	if (s.length() > -1) cout << "okkk" << endl;
	// str.length()�ķ���ֵ��unsigned int�����ֱ����-1�ȽϵĻ����ȽϵĹ���int�ᱻ��ʽת����unsigned int������-1���ɺܴ����

	if ((int)s.length() > -1) cout << "yes" << endl; 
	// ��s.length() ����ֵǿ��ת��Ϊint���ͼ��� һ��Ƚ϶�����ǿ��ת����Ϊ��ȫŶ��

	s += "a";
	cout << s << endl;
	const char* s1 = "abc";
	s = s1;
	cout << s << endl; // abc
	s += "a";
	cout << s << endl; // abca ֤��stringֻ��������s1
	cout << s1 << endl; // abc
	return 0;
	 
}
