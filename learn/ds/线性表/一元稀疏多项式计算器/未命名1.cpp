// 一次失败的做法。
// 一开始读取多项式时，应该直接根据t修改系数，且系数为0则不加入结点！另外空表需要输出结果0，烦的。 
#include<iostream>
using namespace std;
typedef struct node {
	int c, e;
	node *next;
	node(int p, int q):c(p),e(q),next(NULL){}
	node():next(NULL){}
}node;
// 读取多项式 
void read(int x, node*& u, node*& L) {
	int p, q;
	for (int i = 0; i < x; i++) {
		cin >> p >> q;
		// 若系数为0则直接跳过 
		if (p == 0) continue; 
		node* t = new node(p, q);
		// 如果是第一个数或者输入的指数大于上一个指数则直接插入 
		if (u == L || u->e < q) {
			u->next = t;
			u = u->next;
		}
		// 否则寻找插入位置 
		else {
			node *t1 = L->next, *t2 = L->next;
			while (t1 != NULL && q > t1->e) {
				t2 = t1;
				t1 = t1->next;
			}
			if (t1 == L->next) {
				t->next = L->next;
				L->next = t; 
			} else {
				t2->next = t;
				t->next = t1;
			}
		}
	}
}
int main() {
	int n, m, t;
	node *a = new node();
	node *b = new node();
	cin >> n >> m >> t;
	node *la = a, *lb = b, *prev = a;
	read(n, la, a);
	read(m, lb, b);
	la = a->next; lb = b->next;
	// 进行多项式加减 a = a + b 
	while (la != NULL && lb != NULL) {
		// 如果la指数小于lb指数则不变 
		if(la->e < lb->e) {
			prev = la;
			la = la->next;
		} 
		// 如果指数相等则系数进行加减求和 
		else if (la->e == lb->e) {
			// 根据t进行加或减 
			int sum = t ? la->c - lb->c : la->c + lb->c;
			// 若等于0则删除结点 
			if (sum == 0) {
				prev->next = la->next;
				node *t = la;
				la = la->next;
				delete(t);
				lb = lb->next;
			} 
			// 否则就修改结点系数 
			else {
				la->c = sum;
				prev = la;
				la = la->next;
				lb = lb->next;
			}
		} 
		// 如果la指数大于lb指数则将lb结点插入la前面 
		else if (la->e > lb->e) {
			node *t = new node(lb->c, lb->e);
			prev->next = t;
			t->next = la;
			prev = prev->next;
			lb = lb->next;
		}
	}
	// 若b还有剩余则将b中剩余结点插入a 
	while (lb != NULL) {
		node* k = new node();
		if (t == 1) {k->c = -lb->c; k->e = lb->e;}
		else {k->c = lb->c; k->e = lb->e;}
		prev->next = k;
		prev = prev->next;
		lb = lb->next;
	}
	la = a->next;
	// 若a为空，则多项式为0 
	if (la == NULL) printf("0");
	// 输出多项式 
	while (la != NULL) {
		if (la != a->next && la->c > 0) printf("+");
		if (la->e == 0) printf("%d", la->c);
		else if (la->e == 1) {
			if (la->c == 1) printf("x");
			else if (la->c == -1) printf("-x");
			else printf("%dx", la->c);
		} 
		else {
			if (la->c == 1) printf("x^%d", la->e);
			else if (la->c == -1) printf("-x^%d", la->e);
			else printf("%dx^%d", la->c, la->e);
		}
		la = la->next;
	}
	return 0;
} 
