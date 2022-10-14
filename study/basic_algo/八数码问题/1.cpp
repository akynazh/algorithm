/*
八个正方形滑块摆成3行3列（一个格子留空）给初始和目标情况 求最少移动空格（上下左右方向）步数
input
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
output
31
*/
#include <bits/stdc++.h>
using namespace std;
typedef int State[9]; // 把"State"定义为含9个整型元素的数组
const int maxstate = 1000000; // 最多可能出现的情况数
State st[maxstate], goal; // st为所有情况的查找表，goal为目标情况
int dist[maxstate]; // 步数数组
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int hashsize = 1000003;
int head[hashsize], collision[maxstate]; // 哈希表和对应的查找表 当collision[i]不等于0是证明产生了哈希碰撞，需要进行具体比较

void init_lookup_table() {
    memset(head, 0, sizeof(head));
}
int hash_(State& s) { // 生成哈希值
    int v = 0;
    for (int i = 0; i < 9; i++) v = v * 10 + s[i];
    return v % hashsize;
}
int try_to_insert(int s) {
    int h = hash_(st[s]); // 生成哈希值
    // 从哈希表中查找冲突元素
    int u = head[h]; 
    while (u) {
        if (memcmp(st[s], st[u], sizeof(s)) == 0) return 0; // 插入失败
        u = collision[u];
    }
    collision[s] = head[h]; // 记录哈希碰撞，若为0则代表不产生冲突
    head[h] = s; // 建立哈希映射, 将哈希值映射到st下标
    return 1; // 插入成功
}
int bfs() { // 返回所在情况st下标
    init_lookup_table(); // 初始化查找表
    int front = 1, rear = 2; // 不使用0，0看作不存在
    while (front < rear) {
        State& s = st[front]; // s引用了st[front]，即旧位置处
        if (memcmp(goal, s, sizeof(s)) == 0) return front; // 找到目标情况
        int z;
        for (z = 0; z < 9; z++) if (!s[z]) break; // 寻找空格所在位置
        int x = z / 3, y = z % 3; // 获取空格所在行列下标
        for (int d = 0; d < 4; d++) {
            int newx = x + dx[d], newy = y + dy[d];
            int newz = newx * 3 + newy;
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
                State& t = st[rear]; // t引用了st[rear]，即新位置处
                // 移动空格
                memcpy(&t, &s, sizeof(s));
                t[newz] = s[z];
                t[z] = s[newz];
                dist[rear] = dist[front] + 1;
                if (try_to_insert(rear)) rear++; // 成功插入则修改队尾指针
            }
        }
        front++;
    }
    return 0; // 失败
}
int main() {
    for (int i = 0; i < 9; i++) scanf("%d", &st[1][i]);
    for (int i = 0; i < 9; i++) scanf("%d", &goal[i]);
    int ans = bfs();
    if (ans > 0) printf("%d\n", dist[ans]);
    else printf("-1\n");
    return 0;
}