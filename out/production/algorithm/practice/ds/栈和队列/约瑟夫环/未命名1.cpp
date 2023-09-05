#include<iostream>
using namespace std;
typedef struct node {
	int pwd;
	int num;
	node *next;
	node():next(NULL){}
}node, *linkList, *first;
void createList(int n, linkList& list) {
	node* head = new node();
	node* p = head;
	for (int i = 1; i <= n; i++) {
		node* q = new node();
		cin >> q->pwd;
		q->num = i;
		p->next = q;
		p = q;
	}
	p->next = head->next; // 构造循环队列
	list = head->next;
} 
int getNum(int& sum, int& pwd, first& p, first& prev) {
	if (sum == 1) return p->num;
	int t = pwd % sum;
	if (t == 0) t = sum;
	for (int i = 1; i < t; i++) {
		prev = p;
		p = p->next;
	}
	sum--;
	pwd = p->pwd;
	int num = p->num;
	prev->next = p->next;
	node *r = p;
	p = p->next;
	delete(r);
	return num;
}
int main() {
	int n, m, sum, pwd;
	cin >> n >> m;
	sum = n;
	pwd = m;
	linkList list;
	createList(n, list);
	first p = list;
	first prev = list;
	for (int i = 1; i <= n; i++) 
		printf("%d ", getNum(sum, pwd, p, prev));
	return 0;
}
