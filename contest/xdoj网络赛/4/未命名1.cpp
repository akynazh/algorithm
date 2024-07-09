#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
typedef long long LL; 
struct Tree{
	int l, r;
	LL sum;
}; 
Tree tree[4000010];
long long a[1000010], n, hair = 0, ans;
struct District{
	int l, r;
	LL sum;
};
bool cmp(District d1, District d2){
	if(d1.sum > d2.sum)	return true;
	if(d1.sum == d2.sum)	return d1.r - d1.l <= d2.r - d2.l;
	if(d1.sum < d2.sum)	return false;
}
vector<District> v;
void BuildTree(int i, int l, int r){
	tree[i].l = l;
	tree[i].r = r;
	if(l == r){
		tree[i].sum = a[l];
		return;
	}
	int mid = (l + r) / 2;
	BuildTree(2 * i, l, mid);
	BuildTree(2 * i + 1, mid + 1, r);
	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}
void GetSum(int i, int l, int r){
	if(tree[i].l > r || tree[i].r < l)	return;
	if(tree[i].l >= l && tree[i].r <= r){
		ans += tree[i].sum;
		return;
	}
	int mid = (l + r) / 2;
	if(tree[i * 2].r >= l)	GetSum(i * 2, l, r);
	if(tree[i * 2 + 1].l <= r)	GetSum(i * 2 + 1, l, r);
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		stringstream ss(s);
		int x;
		ss >> x;
		a[i] = x; 
		hair += x;
	}
	BuildTree(1, 1, n);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ans = 0;
			GetSum(1, i, j);
			District d;
			d.l = i; d.r = j; d.sum = ans;
			v.push_back(d);
		}
	}
	sort(v.begin(), v.end(), cmp);
	if(v[0].sum > 0)	hair += v[0].sum;
	LL hair1, hair2;
	for(int i = 1; i < v.size(); i++){
		if(v[i].l > v[0].l && v[i].r < v[0].r){
			hair1 = 0;
			break;
		}
		if(v[i].sum < 0){
			hair1 = 0;
			break;
		}
		if(v[i].l > v[0].r || v[i].r < v[0].l){
			hair1 = v[i].sum;
			break;
		}
	}
	for(int i = v.size()-1; i >= 1; i--){
		if(v[0].sum <= 0){
			hair2 = 0;
			break;
		}
		if(v[i].sum > 0){
			hair2 = 0;
			break;
		}
		if(v[i].l >= v[0].l && v[i].r <= v[0].r){
			hair2 = v[i].sum;
			break;
		}
	}
//	for(int i = 0; i < v.size(); i++){
//		cout << v[i].sum << endl;
//	}
//	cout << hair << " "<< hair1 << " " << hair2 << endl;	
	if(hair2 < 0)	hair2 = -hair2;
	hair += max(hair1, hair2);
	cout << hair;
	return 0;
}
