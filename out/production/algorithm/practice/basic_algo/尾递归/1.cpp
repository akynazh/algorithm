//β�ݹ�
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
26 //ֱ�ӵݹ�������ĳ��� 
27 int GetLengthRecursive(linklist head)
28 {
29     if(head->next == NULL)
30        return 0;
31     return (GetLengthRecursive(head->next) + 1);
32 }
33 //����β�ݹ�������ĳ��ȣ���������acc���浱ǰ����ĳ��ȣ����ϵ��ۼ� ֱ����ջ���õ���
34 int GetLengthTailRecursive(linklist head,int *acc)
35 {
36     if(head->next == NULL)
37       return *acc;
38     *acc = *acc+1;
39     return GetLengthTailRecursive(head->next,acc);
40 }
*/ 
