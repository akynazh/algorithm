#include<cstdio>
#include<cstring>
//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
struct Node{
	int v, left, right, valued; 
};
Node node[257];
char s[10000];
int cnt = 1;
int NewNode(){
	int u = ++cnt;
	node[u].left = node[u].right = node[u].valued = 0;
	return u;
}
void AddNode(int v, char *s){
	int len = strlen(s), u = 1;
	for(int i = 0; i < len - 1; i++){
		if(s[i] == 'L'){
			if(node[u].left == 0)	node[u].left = NewNode();
			u = node[u].left;
		}else if(s[i] == 'R'){
			if(node[u].right == 0)	node[u].right = NewNode();
			u = node[u].right;
		}
	}
	node[u].v = v;
	node[u].valued = 1;
	return;
}
void Traverse(int u){
	if(node[u].valued){
		printf("%d ", node[u].v);
		Traverse(node[u].left);
		Traverse(node[u].right);
	}
	return;
}
int main(){
	node[1].left = node[1].right = node[1].valued = 0;
	while(scanf("%s", s) == 1){
		if(!strcmp(s, "()"))	break;
		int v;
		sscanf(&s[1], "%d", &v);
		AddNode(v, strchr(s, ',') + 1);
	}
	Traverse(1); 
	return 0;
} 
