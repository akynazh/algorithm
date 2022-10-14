#include<cstdio>
int main(){
	int x;
	sscanf("666jzh", "%d", &x);
	printf("%d\n", x);

	char str[100];
	sscanf("1234abcd", "%*d%s", str);//整型数据不读入。 
	printf("%s\n",str);
	
	char s[100];
	sprintf(s, "the x: %d", x);
	printf("%s\n", s);
	
	return 0;
}
