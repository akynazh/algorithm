#include<iostream>
#include<list>
using namespace std;

void printlist(const list<int> &L)
{
	for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
		cout << *it << ' ';
	cout << endl;
}

bool cmp(int v1, int v2)
{
	return v1 > v2;
}

int main()
{
	list<int> L1;
	L1.push_back(10);L1.push_back(50);L1.push_back(30);L1.push_back(20);
	printlist(L1);//10 50 30 20
	L1.sort();
	printlist(L1);//10 20 30 50 
	L1.reverse();
	printlist(L1);//50 30 20 10 

	list<int> L2;
	L2.push_back(34);L2.push_back(23);L2.push_front(90);L2.push_front(12);
	L2.sort(cmp); // 由大到小排序
	printlist(L2);//90 34 23 12 

	// 将大小扩充为12，多余元素用100代替
	L2.resize(12, 100);
	printlist(L2);//90 34 23 12 100 100 100 100 100 100 100 100 
	// remove对于list来说是直接删除
	L2.remove(100);
	printlist(L2);//90 34 23 12 
	L2.swap(L1);
	printlist(L2);//50 30 20 10 
	L2 = L1;
	printlist(L2);//90 34 23 12
	L2.pop_front();
	printlist(L2);//34 23 12
	L2.insert(L2.begin(), 10, 100);
	printlist(L2);//100 100 100 100 100 100 100 100 100 100 34 23 12 
	list<int>::iterator it = L1.begin();
	it++;
	printlist(L1);//90 34 23 12 
	L1.erase(it);
	printlist(L1);//90 23 12 
	L1.insert(++L1.begin(),L2.begin(), L2.end());
	printlist(L1);//90 100 100 100 100 100 100 100 100 100 100 34 23 12 23 12 
	L1.clear();
	printlist(L1);//  
	return 0;
}
