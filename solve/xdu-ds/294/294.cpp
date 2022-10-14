#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    scanf("%d", &n);
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (i % 2 != 0) v1.push_back(t);
        else v2.push_back(t);
    }
    for (int i = 0; i < (int)v1.size(); i++) printf("%d ", v1[i]);
    for (int i = 0; i < (int)v2.size(); i++) printf("%d ", v2[i]);
    return 0;
}
