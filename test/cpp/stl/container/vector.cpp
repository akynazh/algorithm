#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std; 

void printvec(vector<int>& v)
{
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)	cout << *it << ' ';
	cout << endl;
}

int main()
{
	vector<int> v1;
	for(int i = 0; i < 10; i++)	v1.push_back(i);
	printvec(v1);//0 1 2 3 4 5 6 7 8 9 
	v1.pop_back();
	printvec(v1);//0 1 2 3 4 5 6 7 8

	vector<int> v2(v1);
	printvec(v2);//0 1 2 3 4 5 6 7 8
	vector<int> v3 = v2;
	printvec(v3);//0 1 2 3 4 5 6 7 8

	if(!v3.empty())	cout << "v3非空" << endl;// v3非空
	v3.resize(15, 2);
	printvec(v3);//0 1 2 3 4 5 6 7 8 2 2 2 2 2 2 

	vector<int> v4;
	v4.reserve(100);//如果数据量较大，可以一开始利用reserve预留空间 
	for(int i = 0; i < 100; i++)	v4.push_back(i);
	v4.resize(3); 
	printvec(v4); // 0 1 2
	//匿名对象，换后被清除 
	vector<int>(v4).swap(v4);//swap可以使两个容器互换，可以达到实用的收缩内存效果
	printvec(v4);//0 1 2	
	cout << v4.front() << ' ' << v4.back() << endl;//0 2 
	v4.insert(v4.begin(), 5, 6);
	printvec(v4); //6 6 6 6 6 0 1 2 
	v4.erase(v4.begin()+5); // 删除第六个数
	printvec(v4);//6 6 6 6 6 1 2 

	// 重要！对于vector来说remove是将要删除的对象放到容器末尾，并返回一个指向第一个要删除元素的指针
	// 对于其他则是直接删除啦
	vector<int>::iterator it = remove(v4.begin(), v4.end(), 6);
	printvec(v4);
	v4.erase(it, v4.end());
	printvec(v4);
	return 0; 
}
