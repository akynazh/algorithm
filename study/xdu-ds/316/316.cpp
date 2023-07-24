#include <bits/stdc++.h>
using namespace std;
int x, y;
vector<int> v;

int main() {
    for (;;) {
        scanf("%d%d", &x, &y);
        if (x == 0 && y == 0) break;
        v.clear();
        while (x) {v.push_back(x); x /= 2;}
        int idx = 0;
        while (y) { 
            while (y < v[idx]) idx++;
            if (y == v[idx]) {
                printf("%d\n", y);
                break;
            }
            y /= 2;
        }
    }    
    return 0;
}