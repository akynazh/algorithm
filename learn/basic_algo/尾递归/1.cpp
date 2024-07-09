//尾递归
#include<iostream>

using namespace std;

int Fibonacci(int n, int ret1, int ret2)
{
	if(n == 0)	return ret1;
	return Fibonacci(n-1, ret2, ret1+ret2);	
} 

int main()
{
	int n, m;
	cin >> n;
	cout << Fibonacci(n, 0, 1);
	return 0;
}
/*
26 //直接递归求链表的长度 
27 int GetLengthRecursive(linklist head)
28 {
29     if(head->next == NULL)
30        return 0;
31     return (GetLengthRecursive(head->next) + 1);
32 }
33 //采用尾递归求链表的长度，借助变量acc保存当前链表的长度，不断的累加 直接在栈顶得到答案
34 int GetLengthTailRecursive(linklist head,int *acc)
35 {
36     if(head->next == NULL)
37       return *acc;
38     *acc = *acc+1;
39     return GetLengthTailRecursive(head->next,acc);
40 }
*/ 
