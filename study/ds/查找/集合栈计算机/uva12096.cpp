#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end() // 集合x中所有元素
#define INS(x) inserter(x, x.begin()) // inserter构造一个插入迭代器，从x指向的位置(第二个参数)开始的连续位置将新元素插入x中
using namespace std;
typedef set<int> Set;
map<Set, int> IDcache; // 将各个独特的集合映射为ID
vector<Set> Setcache; // 通过集合ID查找对应集合
int T, N;
int ID (Set x) {
    if (IDcache.count(x)) return IDcache[x]; //如果已经存在该集合
    Setcache.push_back(x); // 添加新的集合
    return IDcache[x] = Setcache.size() - 1;
}
void solve() {
    stack<int> s;
    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;
        if (op[0] == 'P') s.push(ID(Set()));
        else if (op[0] == 'D') s.push(s.top());
        else {
            Set x1 = Setcache[s.top()]; s.pop();
            Set x2 = Setcache[s.top()]; s.pop();
            Set x;
            if (op[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));
            if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
            if (op[0] == 'A') {x = x2; x.insert(ID(x1));}
            s.push(ID(x));
        }
        cout << Setcache[s.top()].size() << endl;
    }
    cout << "***" << endl;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        IDcache.clear();
        Setcache.clear();
        scanf("%d", &N);
        solve();
    }
    return 0;
}