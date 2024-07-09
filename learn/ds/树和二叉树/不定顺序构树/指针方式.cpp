#include<cstdio>
#include<cstring>
//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
struct Node{
	int v;
	Node *left, *right;
	Node(): left(NULL), right(NULL){}
};
Node *node = new Node();
char s[10000];
void AddNode(int v, char *s){
	int len = strlen(s);
	Node *u = node;
	for(int i = 0; i < len - 1; i++){
		if(s[i] == 'L'){
			if(u->left == NULL)	u->left = new Node();
			u = u->left;	
		}else if(s[i] == 'R'){
			if(u->right == NULL)	u->right = new Node();
			u = u->right;
		}
	}
	u->v = v;
	return;
}
void PreTraverse(Node* u){
	if(u){
		printf("%d ", u->v);
		PreTraverse(u->left);
		PreTraverse(u->right);
	}
	return;
}
int main(){
	while(scanf("%s", s) == 1){
		if(!strcmp(s, "()"))	break;
		int v;
		sscanf(&s[1], "%d", &v);
		AddNode(v, strchr(s, ',') + 1);
	}
	PreTraverse(node);
	return 0;
} 
