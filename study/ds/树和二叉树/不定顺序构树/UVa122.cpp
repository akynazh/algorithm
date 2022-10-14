#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
struct Node{
	int v, valued;
	Node *left, *right;
	Node(): valued(0), left(NULL), right(NULL){}
};
Node *node;
char s[10000];
vector<int> ans;
bool fail;
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
	if(u->valued == 1)	fail = true;
	u->v = v;
	u->valued = 1;
	return;
}
bool ReadInput(){
	node = new Node();
	fail = false;
	while(1){
		if(scanf("%s", s) != 1)	return false;
		if(strcmp(s, "()") == 0)	break;
		int v;
		sscanf(&s[1], "%d", &v);
		AddNode(v, strchr(s, ',') + 1);
	}
	return true;
}
bool Bfs(){
	queue<Node*> q;
	q.push(node);
	ans.clear();
	while(!q.empty()){
		Node *u = q.front();
		q.pop();
		if(!u->valued)	return false;
		ans.push_back(u->v);
		if(u->left != NULL)	q.push(u->left);
		if(u->right != NULL)	q.push(u->right);
	}
	return true;
}
int main(){
	while(ReadInput()){
		if(fail)	printf("not complete\n");
		else if(!Bfs())	printf("not complete\n");
		else{
			for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
				if(it + 1 == ans.end())	printf("%d\n", *it);
				else printf("%d ", *it);
			}
		}
	}
	return 0;
} 
