#include<iostream>
#include<numeric>
#include<vector> 
using namespace std;

int main()
{
	vector<double> v1;
	v1.push_back(5.2);v1.push_back(3);v1.push_back(45);v1.push_back(5);
	v1.push_back(62);v1.push_back(2);v1.push_back(5);v1.push_back(6);
	double sum1 = accumulate(v1.begin(), v1.end(), 0);//133
	double sum2 = accumulate(v1.begin(), v1.end(), 0.0);//133.2
	cout << sum1 << endl;
	cout << sum2 << endl;
	double ave = accumulate(v1.begin(), v1.end(), 0.0) / v1.size();
	cout << ave << endl;//16.65
	vector<double> v2;
	v2.resize(12);
	fill(v2.begin(), v2.end(), 100);//多用于后期改变 
	for(vector<double>::iterator it = v2.begin(); it != v2.end(); it++)
		cout << *it << " ";//100 100 100 100 100 100 100 100 100 100 100 100
}
