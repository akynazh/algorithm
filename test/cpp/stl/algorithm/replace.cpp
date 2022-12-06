#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(int val)
{
	cout << val << " ";
}

bool great10(int val)
{
	return val >= 10;
}

int main()
{
	// initial
	vector<int> v1;
	vector<int> v2;
	v1.push_back(5);v1.push_back(3);v1.push_back(45);v1.push_back(5);v1.push_back(61);
	v1.push_back(62);v1.push_back(2);v1.push_back(5);v1.push_back(6);
	v2.push_back(45);v2.push_back(57);v2.push_back(3);v2.push_back(23);
	for_each(v1.begin(), v1.end(), print);//5 3 45 5 61 62 2 5 6
	cout << endl;
	for_each(v2.begin(), v2.end(), print);//45 57 3 23
	cout << endl;

	// 将指定值更换为新值
	replace(v1.begin(), v1.end(), 5, 500);
	for_each(v1.begin(), v1.end(), print);//500 3 45 500 61 62 2 500 6 
	cout << endl;

	replace_if(v1.begin(), v1.end(), great10, 100);
	for_each(v1.begin(), v1.end(), print);//100 3 100 100 100 100 2 100 6
	cout << endl;

	// 更换容器！挺重要的感觉
	swap(v1, v2);
	for_each(v2.begin(), v2.end(), print);//100 3 100 100 100 100 2 100 6
	cout << endl;

	vector<int> v3;
	//v3.resize(v2.size());
	v3 = v2;//用拷贝构造不需要提前开辟空间 
	//copy(v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), print);//100 3 100 100 100 100 2 100 6
	cout << endl;
	return 0; 
}
