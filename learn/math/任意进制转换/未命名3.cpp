#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n, m, ccount = -1, sum = 0;
	string s;
	cin >> n >> s >> m;
	vector<int> v;
	for(int i = 0; i < s.length(); i++){
		int t;
		if(isalpha(s[i]))	t = s[i] - 'A' + 10;
		else t = s[i] - '0';
		v.push_back(t);
		ccount++;
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		sum += *it * (int)(pow(n, ccount));
		ccount--;
	}
	string st;
	while(sum){
		int t = sum % m;
		if(t >= 10)	st += t - 10 + 'A';
		else st += t + '0';
		sum /= m;
	}
	for(int i = st.size() - 1; i >= 0; i--)	cout << st[i];
	return 0;
}
