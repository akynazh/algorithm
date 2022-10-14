#include<iostream>
#include<set> 
#include<string>
using namespace std;

class Person{
public:
	Person(int age, string name)
	{
		m_age = age;
		m_name = name;
	}
	
	int m_age;
	string m_name;	
};

class cmp{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.m_age > p2.m_age;
	}
};

class cmp1{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void printset(set<int> &s)
{
	for(set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}
void printmultiset(multiset<int> &s)
{
	for(multiset<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	set<int> s1;
	s1.insert(12);s1.insert(34);s1.insert(2);s1.insert(11);s1.insert(2);
	printset(s1);//2 11 12 34
	multiset<int> s2;
	s2.insert(12);
	s2.insert(34);
	s2.insert(2);
	s2.insert(11);
	s2.insert(2);
	printmultiset(s2);//2 2 11 12 34
	set<int>::iterator itt = s2.find(2);
	cout << *itt << endl;//2
	itt++;
	cout << *itt << endl;//2
	// ?key==2?????
	int c = s2.count(2);
	cout << c << endl;//2
	s2.erase(2);
	printmultiset(s2);// 11 12 34
	set<int, cmp1> s3;
	s3.insert(12);
	s3.insert(34);
	s3.insert(2);
	s3.insert(11);
	for(set<int, cmp1>::iterator it = s3.begin(); it != s3.end(); it++)
		cout << *it  << " ";//34 12 11 2
	cout << endl;
	set<Person, cmp> s4;
	Person p1(213, "³ôÖí");
	Person p2(23434, "¹ÏÍŞ");
	Person p3(349, "Âé¹Ï"); 
	Person p4(4989, "öÏÓã");
	s4.insert(p1);
	s4.insert(p2);
	s4.insert(p3);
	s4.insert(p4);
	for(set<Person, cmp>::iterator it = s4.begin(); it != s4.end(); it++)
		cout << it->m_name << " " << it->m_age<<endl;
	cout << endl; 
	/*
	¹ÏÍŞ 23434
	öÏÓã 4989
	Âé¹Ï 349
	³ôÖí 213
	*/
	pair<int, string>  pp(232313, "ÖíÖíÖí");
	cout << pp.first << " " << pp.second;
	cout << endl; 
	return 0;
}
