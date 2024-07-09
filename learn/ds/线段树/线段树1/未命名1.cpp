#include<cstdio>
typedef long long LL;
int n, m; 
long long Sum = 0, a[100000];
struct Tree{
	int l, r;
	long long sum, lazy = 0;
}; 
Tree tree[400010];//必须开四倍空间，二倍空间是完全二叉树下的
//建树 
void BuildTree(int i, int l, int r){
	tree[i].l = l;
	tree[i].r = r;
	if(l == r){
		tree[i].sum = a[l];
		return;
	}
	int mid = (l + r) / 2;
	BuildTree(i * 2, l, mid);
	BuildTree(i * 2 + 1, mid + 1, r);
	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
	return;
}
//懒惰标记 
void PushDown(int i){
	if(tree[i].lazy){
		tree[i * 2].sum += 1LL * (tree[i * 2].r - tree[i * 2].l + 1) * tree[i].lazy;
		tree[i * 2 + 1].sum += 1LL * (tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1) * tree[i].lazy;
		tree[i * 2].lazy += tree[i].lazy;
		tree[i * 2 + 1].lazy += tree[i].lazy;
		tree[i].lazy = 0;
	}
	return;
}
//区间修改 
void Change(int i, int l, int r, int k){
	if(tree[i].l >= l && tree[i].r <= r){
		tree[i].sum += 1LL * (tree[i].r - tree[i].l + 1) * k;
		tree[i].lazy += 1LL * k;
		return;
	}	 
	PushDown(i);
	if(tree[i * 2].r >= l)	Change(i * 2, l, r, k);
	if(tree[i * 2 + 1].l <= r)	Change(i * 2 + 1, l, r, k);
	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
	return;
}
//区间查找 
void GetSum(int i, int l, int r){
	if(tree[i].l >= l && tree[i].r <= r){
		Sum += tree[i].sum;
		return;
	}
	PushDown(i);
	if(tree[i].l > r || tree[i].r < l)	return;
	if(tree[i * 2].r >= l)	GetSum(i * 2, l, r);
	if(tree[i * 2 + 1].l <= r)	GetSum(i * 2 + 1, l, r);
	return;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	BuildTree(1, 1, n);
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int x, y, k;
			scanf("%d%d%d", &x, &y, &k);
			Change(1, x, y, k);
		}
		else if(t == 2){
			int x, y;
			scanf("%d%d", &x, &y);
			GetSum(1, x, y);
			printf("%lld\n", Sum);
			Sum = 0; 
		}
	}
	return 0;	
}
