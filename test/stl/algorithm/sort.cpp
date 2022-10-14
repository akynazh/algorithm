#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

void print(int val)
{
	cout << val << " ";
}

bool cmp(int v1, int v2)
{
	return v1%10 > v2%10;
}

int main()
{
	srand((unsigned int) time (NULL));
	vector<int> v1;
	vector<int> v2;
	v1.push_back(23);v1.push_back(3);v1.push_back(43);v1.push_back(9);v1.push_back(61);
	v1.push_back(62);v1.push_back(2);v1.push_back(9);v1.push_back(6);
	v2.push_back(45);v2.push_back(57);v2.push_back(3);v2.push_back(23);
	
	sort(v1.begin(), v1.end());//£¡£¡ 
	for_each(v1.begin(), v1.end(), print);//2 3 6 9 9 23 43 61 62 
	
	sort(v2.begin(), v2.end());//£¡£¡ 
	cout << endl;
	for_each(v2.begin(), v2.end(), print);//3 23 45 57
	cout << endl;
	vector<int> v3;
	
	v3.resize(v1.size()+v2.size());
	
	// ??????????????????
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), print);//2 3 3 6 9 9 23 23 43 45 57 61 62
	reverse(v3.begin(), v3.end());
	cout << endl;
	for_each(v3.begin(), v3.end(), print);//62 61 57 45 43 23 23 9 9 6 3 3 2
	// ????v3???
	srand((unsigned)time(NULL));
	random_shuffle(v3.begin(), v3.end()); 
	cout << endl;
	for_each(v3.begin(), v3.end(), print);//6 57 3 43 9 23 62 2 3 61 23 45 9
	sort(v3.begin(), v3.end(), cmp);
	cout << endl;
	for_each(v3.begin(), v3.end(), print);//9 9 57 6 45 43 3 23 3 23 62 2 61
	return 0;	
}
 
