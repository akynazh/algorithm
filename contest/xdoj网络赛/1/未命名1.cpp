#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n;
int main(){
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int c = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '1'){
				c++;
				while(i < s.length() && s[i] == '1')	i++;
			}
		}
		cout << c << endl;
	}
	return 0;
}
