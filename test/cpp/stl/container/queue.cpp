#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Person{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age =age;
	}
	string m_name;
	int m_age;
};

int main()
{
	queue<Person> q;
	Person p1("����", 1200);	Person p2("����", 1245);
	Person p3("���", 233);		Person p4("��«��", 1);
	q.push(p1); q.push(p2); q.push(p3); q.push(p4);
	while(!q.empty()){
		cout << q.front().m_name << ' ' << q.front().m_age << ' '
		     << q.back().m_name  << ' ' << q.back().m_age << ' ' << endl;
		q.pop(); 
	}
	/* 
	���� 1200 ��«�� 1
	���� 1245 ��«�� 1
	��� 233 ��«�� 1
	��«�� 1 ��«�� 1
	*/ 
	return 0;
}
