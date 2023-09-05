// һ��ʧ�ܵ�������
// һ��ʼ��ȡ����ʽʱ��Ӧ��ֱ�Ӹ���t�޸�ϵ������ϵ��Ϊ0�򲻼����㣡����ձ���Ҫ������0�����ġ� 
#include<iostream>
using namespace std;
typedef struct node {
	int c, e;
	node *next;
	node(int p, int q):c(p),e(q),next(NULL){}
	node():next(NULL){}
}node;
// ��ȡ����ʽ 
void read(int x, node*& u, node*& L) {
	int p, q;
	for (int i = 0; i < x; i++) {
		cin >> p >> q;
		// ��ϵ��Ϊ0��ֱ������ 
		if (p == 0) continue; 
		node* t = new node(p, q);
		// ����ǵ�һ�������������ָ��������һ��ָ����ֱ�Ӳ��� 
		if (u == L || u->e < q) {
			u->next = t;
			u = u->next;
		}
		// ����Ѱ�Ҳ���λ�� 
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
	// ���ж���ʽ�Ӽ� a = a + b 
	while (la != NULL && lb != NULL) {
		// ���laָ��С��lbָ���򲻱� 
		if(la->e < lb->e) {
			prev = la;
			la = la->next;
		} 
		// ���ָ�������ϵ�����мӼ���� 
		else if (la->e == lb->e) {
			// ����t���мӻ�� 
			int sum = t ? la->c - lb->c : la->c + lb->c;
			// ������0��ɾ����� 
			if (sum == 0) {
				prev->next = la->next;
				node *t = la;
				la = la->next;
				delete(t);
				lb = lb->next;
			} 
			// ������޸Ľ��ϵ�� 
			else {
				la->c = sum;
				prev = la;
				la = la->next;
				lb = lb->next;
			}
		} 
		// ���laָ������lbָ����lb������laǰ�� 
		else if (la->e > lb->e) {
			node *t = new node(lb->c, lb->e);
			prev->next = t;
			t->next = la;
			prev = prev->next;
			lb = lb->next;
		}
	}
	// ��b����ʣ����b��ʣ�������a 
	while (lb != NULL) {
		node* k = new node();
		if (t == 1) {k->c = -lb->c; k->e = lb->e;}
		else {k->c = lb->c; k->e = lb->e;}
		prev->next = k;
		prev = prev->next;
		lb = lb->next;
	}
	la = a->next;
	// ��aΪ�գ������ʽΪ0 
	if (la == NULL) printf("0");
	// �������ʽ 
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
