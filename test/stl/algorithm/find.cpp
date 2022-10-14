#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct Person{
	Person(int age, string s)
	{
		m_age = age;
		m_name = s;
	}
	bool operator==(const Person &p)//�����const 
	{
		if(p.m_age == m_age && p.m_name == m_name)
			return true;
		else 
			return false;
	}
	int m_age;
	string m_name;
};

class Greater50{
public:
	bool operator()(Person &p)
	{
		return p.m_age > 50;
	}
};

int main()
{
	vector<Person> v;
	Person p1(35,"���");Person p2(66, "����");Person p3(20,"����");Person p4(55, "����");
	Person p5(23, "����");Person p6(23, "����");Person p7(23, "����");
	Person x(23, "����");Person y(32,"����"); 
	v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p4); v.push_back(p5);v.push_back(p6);v.push_back(p7);

	// findѰ������v��ֵΪy�Ķ���
	vector<Person>::iterator it = find(v.begin(), v.end(), y);
	if(it != v.end())	cout << "�ҵ�" << endl;
	else cout << "ľ���ҵ�" << endl;//ľ���ҵ�
	// count��������v��ֵΪx�Ķ������
	int num = count(v.begin(), v.end(), x); 
	cout << num << endl;//3
	
	// ��������
	vector<Person>::iterator it1 = find_if(v.begin(), v.end(), Greater50());
	if(it1 != v.end())	cout << "�ҵ�" << endl;//�ҵ�
	else cout << "ľ���ҵ�" << endl;
	int num1 = count_if(v.begin(), v.end(), Greater50());
	cout << num1 << endl; //2
	
	vector<int> v1; // 5 2 5 2 2 6
	v1.push_back(5); v1.push_back(2); v1.push_back(5); 
	v1.push_back(2); v1.push_back(2); v1.push_back(6); 
	vector<int>::iterator it2 = adjacent_find(v1.begin(), v1.end());
	// Ѱ���Ƿ���������ȵ�Ԫ��
	if(it2 != v1.end())	cout << "�ҵ�" << endl;//�ҵ�
	else cout << "δ�ҵ�" << endl;

	sort(v1.begin(), v1.end());//�������������вſ���ʹ�ö��ֲ��� 
	// ʹ�ö��ֲ����Ƿ��е���5��Ԫ��
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if(ret)	cout << "�ҵ�" << endl;//�ҵ� 
	else cout << "δ�ҵ�" << endl;
}
