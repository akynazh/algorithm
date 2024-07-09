#include <bits/stdc++.h>
using namespace std;
const int maxLen = 100;
/*
ababbabaababaabababaaababaaaba
ababaaababaa
0
*/
void get_next(string T, int *next) {
	next[0] = -1; // �±��0��ʼ���ǿ�ʼ��Ϊ-1(��1��ʼ����Ϊ0) ��Ϊ�ô����ܻ���
	int i = 0, j = -1, tlen = T.length(); // ��ȡ�ַ�T[0..i-1]ǰ��׺�ַ������ƶ� jΪƥ�俪ʼ��
	while (i < tlen) { 
		if (j == -1 || T[i] == T[j]) { // ��jΪ-1��ʾֻ�ܻ��ݵ��±�0
			i++; j++;
			// next[i] = j; // ��ǻ��ݵ� T[i-1]==T[j-1] (0) (�Ľ�ǰ�Ĳ���)
			if (T[i] != T[j]) next[i] = j; 
			else next[i] = next[j]; // ��ǰT[i]==T[j] ��ʱƥ��ʱ��ֻ���ݵ�j��Ҳһ��ƥ�䲻��� ����ֱ��ƥ�䵽����ȵ�λ�� 
		}
		else j = next[j]; // �����Ѿ������˵�next������л���
	}
}

int kmp(string S, string T, int pos) {
	int i = pos, j = 0, slen = S.length(), tlen = T.length();
	int next[maxLen];
	get_next(T, next); // �õ�T��next����
	while (i < slen && j < tlen) {
		if (j == -1 || T[j] == S[i]) {
			i++; j++;
		} 
		else j = next[j]; //��j���л���
	}
	for (int i = 0; i < T.length(); i++) cout << next[i] << " ";cout << endl;
	if (j == tlen) return i - tlen;
	else return -1;
}

int main()
{
	string S, T;
	int pos, ans; //��S[pos]���λ�ÿ�ʼƥ��

	cin >> S >> T >> pos;
	ans = kmp(S, T, pos);
	cout << ans << endl;


	return 0;
}
