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
	bool operator==(const Person &p)//必须加const 
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
	Person p1(35,"麻瓜");Person p2(66, "臭猪");Person p3(20,"瓜娃");Person p4(55, "飞猪");
	Person p5(23, "飞猪");Person p6(23, "飞猪");Person p7(23, "飞猪");
	Person x(23, "飞猪");Person y(32,"飞猪"); 
	v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p4); v.push_back(p5);v.push_back(p6);v.push_back(p7);

	// find寻找容器v中值为y的对象
	vector<Person>::iterator it = find(v.begin(), v.end(), y);
	if(it != v.end())	cout << "找到" << endl;
	else cout << "木有找到" << endl;//木有找到
	// count计算容器v中值为x的对象个数
	int num = count(v.begin(), v.end(), x); 
	cout << num << endl;//3
	
	// 条件查找
	vector<Person>::iterator it1 = find_if(v.begin(), v.end(), Greater50());
	if(it1 != v.end())	cout << "找到" << endl;//找到
	else cout << "木有找到" << endl;
	int num1 = count_if(v.begin(), v.end(), Greater50());
	cout << num1 << endl; //2
	
	vector<int> v1; // 5 2 5 2 2 6
	v1.push_back(5); v1.push_back(2); v1.push_back(5); 
	v1.push_back(2); v1.push_back(2); v1.push_back(6); 
	vector<int>::iterator it2 = adjacent_find(v1.begin(), v1.end());
	// 寻找是否有连续相等的元素
	if(it2 != v1.end())	cout << "找到" << endl;//找到
	else cout << "未找到" << endl;

	sort(v1.begin(), v1.end());//必须是有序序列才可以使用二分查找 
	// 使用二分查找是否有等于5的元素
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if(ret)	cout << "找到" << endl;//找到 
	else cout << "未找到" << endl;
}
