#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct D{
	int l, r;
	int sum;
};
int a[1000010], n, hair = 0;
D d[1000010];
bool cmp(D d1, D d2){
	if(d1.sum > d2.sum)	return true;
	if(d1.sum == d2.sum)	return d1.r - d1.l <= d2.r - d2.l;
	if(d1.sum < d2.sum)	return false;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		hair += a[i];
	}
	d[1].l = d[1].r = 1;
	d[1].sum = a[1];
	for(int i = 2; i <= n; i++){
		if(d[i-1].sum + a[i] <= a[i]){
			d[i].sum = a[i];
			d[i].l = d[i].r = i;
		}else{
			d[i].sum = d[i-1].sum + a[i];
			d[i].l = d[i-1].l;
			d[i].r = i;
		}
	}
	sort(d+1, d+1+n, cmp);
	if(d[1].sum > 0)	hair += d[1].sum;
	int hair1 = 0, hair2 = 0;
	for(int i = 2; i <= n; i++){
		if(d[i].l > d[1].r || d[i].r < d[1].l){
			if(d[i].sum > 0){
				hair1 = d[i].sum;
				break;
			}
		}
	}
	int l = d[1].l, r = d[1].r;
	int mmax = -1000000001;
	int r_max = r;
	for(int i = 2; i <= n; i++){
		if(d[i].l == l && d[i].r > r_max)
			r_max = d[i].r;
	}
	d[r+1].l = d[r+1].r = r+1;
	d[r+1].sum = a[r+1];
	for(int i = r+1+1; i <= r_max; i++){
		if(a[i] + d[i-1].sum < a[i]){
			d[i].sum = a[i];
		}else{
			d[i].sum = a[i] + d[i-1].sum;
		}
		if(d[i].sum > hair1)	hair1 = d[i].sum;
	}
	d[l].l = l;
	d[l].r = l;
	d[l].sum = a[l];
	int mmin = 1000000001;
	for(int i = l+1; i <= r; i++){
		if(d[i-1].sum + a[i] <= a[i]){
			d[i].sum = d[i-1].sum + a[i];
		}else{
			d[i].sum = a[i];
		}
		if(d[i].sum < 0 && d[i].sum < mmin)	mmin = d[i].sum;
	}
	if(mmin < 0)	hair2 = -mmin;
	hair += max(hair1, hair2);
	cout << hair;
	return 0;
}
