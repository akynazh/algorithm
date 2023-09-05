#include<iostream>
#include<string>
using namespace std;
// 由中序和后序遍历求出前序遍历
void solve(string mid, string post){
	if(mid.size() > 0){
	char ch = post[post.size() - 1];
	cout << ch;
	int k = mid.find(ch);
	solve(mid.substr(0, k), post.substr(0, k));
	solve(mid.substr(k+1), post.substr(k, post.size() - k - 1));
	}
	return;
}
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	solve(s1, s2);
	return 0;
}
