#include<deque>
#include<iostream>
#include<algorithm>

using namespace std;

void printdeque(const deque<int>& d)
{
	for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
		cout << *it << ' ';
	cout << endl;
}

int main()
{
	
	deque<int> d1;
	d1.push_back(3);d1.push_back(4);d1.push_front(1);d1.push_front(2);
	printdeque(d1);//2 1 3 4 
	d1.pop_back();
	d1.pop_front();
	printdeque(d1);//1 3 
	cout << d1.front() << " " << d1.back() << endl; // 1 3

	deque<int> d3 = d1;
	printdeque(d3);//1 3 
	d3.resize(10);
	printdeque(d3);//1 3 0 0 0 0 0 0 0 0 
	int j = d3.empty();
	cout << j << endl;// 0 

	for(deque<int>::iterator it = d3.begin()+2; it != d3.end(); it++)
		*it = 5 * (*it + 1) + *(it-1);
	printdeque(d3);//1 3 8 13 18 23 28 33 38 43 
	d3.push_back(3);
	d3.push_back(32);
	d3.push_front(393);
	sort(d3.begin(), d3.end()); // 排序
	printdeque(d3);//1 3 3 8 13 18 23 28 32 33 38 43 393 
	cout << d3[2] << endl;//3 
	return 0;
} 
