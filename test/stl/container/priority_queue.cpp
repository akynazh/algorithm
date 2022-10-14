#include<iostream>
#include<queue>
using namespace std;

struct cmp{
	bool operator()(int v1, int v2)
	{
		return v1%10 > v2%10;
	}
}; 

int main()
{
	//越小的整数优先级越低的优先队列 
	priority_queue<int> s;
	s.push(21);
	s.push(1);
	s.push(221);
	s.push(31);
	s.push(18);
	cout << s.top() << endl;//221
	s.pop();
	cout << s.top() << endl;//31
	
	//越大的整数优先级越低的优先队列 
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(21);
	pq.push(1);
	pq.push(221);
	pq.push(31);
	pq.push(18);
	cout << pq.top() << endl;//1
	pq.pop();
	cout << pq.top() << endl;//18
	
	//各位数字越大的整数优先级越低的优先队列
	priority_queue<int, vector<int>, cmp> pq1;
	pq.push(56);
	pq1.push(75);
	pq1.push(22111);
	pq1.push(88);
	pq1.push(19);
	cout << pq1.top() << endl;//22111
	pq1.pop();
	cout << pq1.top() << endl;//75
	 
	return 0;
}
