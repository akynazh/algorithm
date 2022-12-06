#include<iostream>
#include<map>
#include<string>
using namespace std;

class cmp{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;	
	}
};

void printmap1(map<string, int> &m)
{
	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << it->first << " " << it->second << endl;
}
void printmap2(map<int, int> &m)
{
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << it->first << " " << it->second << endl;
}
int main()
{
	map<string, int> m1;
	pair<string, int> p1("A", 110);
	m1.insert(p1); 	
	m1.insert(pair<string, int>("B", 99));
	m1.insert(pair<string, int>("C", 103));
	m1.insert(pair<string, int>("E", 87));
	printmap1(m1);
	/*
	A 110
	B 99
	C 103
	E 87
	*/
	//插入后的默认排序是根据key值进行的 ！！ ABCE
	cout << m1["A"] << endl;//110
	
	map<int, int> m2;
	m2.insert(pair<int, int>(4, 12));
	m2.insert(pair<int, int>(3, 6));
	m2.insert(pair<int, int>(2, 2));
	m2.insert(pair<int, int>(1, 10));
	printmap2(m2);
	/*
	1 10
	2 2
	3 6
	4 12
	*/
	cout << m2.size() << endl;//4
	cout << m2[3] << endl;//6
	
	multimap<int, int> m3;
	pair<int, int> p2(1,3), p3(2,5), p4(3,14), p5(3,9);
	m3.insert(p2);m3.insert(p3);m3.insert(p4);m3.insert(p5);
	for(multimap<int, int>::iterator it = m3.begin(); it != m3.end(); it++)
		cout << it->first << " " << it->second << endl;
		/*
		1 3
		2 5
		3 14
		3 9
		*/ 
	multimap<int, int>::iterator itt = m3.find(3);
	cout << itt->second << endl;//14
	itt++;
	cout << itt->second << endl;//9
	cout << m3.count(3) << endl;//2
	m3.erase(3);
	for(multimap<int, int>::iterator it = m3.begin(); it != m3.end(); it++)
		cout << it->first << " " << it->second << endl;
	//	1 3
	//	2 5
	map<int, int, cmp> m4;//4 3 2 1
	m4.insert(pair<int, int>(1,213));
	m4.insert(pair<int, int>(2,5323));
	m4.insert(pair<int, int>(3,21343));
	m4.insert(pair<int, int>(4,243));
	for(map<int, int, cmp>::iterator it = m4.begin(); it != m4.end(); it++)
		cout << it->first << " " << it->second << endl;
	/*
	4 243
	3 21343
	2 5323
	1 213
	*/
	return 0;
} 
