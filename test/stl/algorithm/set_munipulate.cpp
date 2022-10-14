#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(int val)
{
	cout << val << " ";
}

int main()
{
	vector<int> v1, v2, v;
	for(int i = 0; i < 10; i++)	v1.push_back(i);
	for(int i = 10; i >= 0 ; i--)	v2.push_back(i+5);
	for_each(v1.begin(), v1.end(), print);//0 1 2 3 4  5 6 7 8 9 
	cout << endl;
	for_each(v2.begin(), v2.end(), print);//15 14 13 12 11 10 9 8 7 6 5
	cout << endl;
	
	sort(v2.begin(), v2.end());
	
	for_each(v2.begin(), v2.end(), print);//5 6 7 8 9  10 11 12 13 14 15
	cout << endl;
	v.resize(min(v1.size(), v2.size()));
	// 取交集 
	vector<int>::iterator itend1 = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	for_each(v.begin(), itend1, print);//5 6 7 8 9
	cout << endl;
	
	for_each(v.begin(), v.end(), print);//5 6 7 8 9 0 0 0 0 0
	v.clear();
	for_each(v.begin(), v.end(), print);//(空)
	cout << endl;
	for_each(v.begin(), itend1, print);//5 6 7 8 9 说明是通过指向性的操作进行的 
	cout << endl;
	
	// 取并集
	v.resize(v1.size() + v2.size());
	vector<int>::iterator itend2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	for_each(v.begin(), itend2, print); //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	//for_each(v.begin(), itend1, print);//崩溃 ，证明之前的指向失效了 
	
	// 取差集
	v.resize(max(v1.size(), v2.size()));
	cout << endl << "v1与v2的差集：" << endl;
	vector<int>::iterator itend3 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	for_each(v.begin(), itend3, print);//0 1 2 3 4
	cout << endl << "v2与v1的差集：" << endl;
	vector<int>::iterator itend4 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v.begin());
	for_each(v.begin(), itend3, print);//10 11 12 13 14
	return 0;
} 
