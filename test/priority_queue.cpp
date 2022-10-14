#include <bits/stdc++.h>
using namespace std;
struct node {
    int r, l, w;
    node (int a, int b, int c) {r = a; l = b; w = c;}
    node () {}
};
struct greaterNode {
    bool operator() (node n1, node n2) {return n1.w > n2.w;}
};
struct lessNode {
    bool operator() (node n1, node n2) {return n1.w < n2.w;}
};
int main() {
    priority_queue<int> q1; // 默认从大到小
    // 传入第三个参数，代表优先级小的意思 如传入greater代表greater的优先级小
    priority_queue<int, vector<int>, greater<int> > q2; // 从小到大
    priority_queue<int, vector<int>, less<int> > q3; // 从大到小
    priority_queue<node, vector<node>, greaterNode> qnode1; // 结点值权小的优先值大
    priority_queue<node, vector<node>, lessNode> qnode2; // 结点值权小的优先值小

}