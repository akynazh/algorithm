#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    int arr[110];
    map<int, int> mp[10010]; // mp[i][j]=k表示第i组的值为j的数出现了k次
    vector<int> vc; // 存取分组号
    vector<int> vr; // 存取出现过的数字
    map<int, int> m1; // 记录出现过的分组号
    map<int, int> m2; // 记录出现过的数字
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        mp->clear();
        m1.clear();
        m2.clear();
        vc.clear();
        vr.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (!m2[arr[i]]) {
                m2[arr[i]] = 1;
                vr.push_back(arr[i]);
            }
        }
        int t;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            if (!m1[t]) { // 如果该组号未出现过
                m1[t] = 1;
                vc.push_back(t);
                mp[t][arr[i]]++;
            } else mp[t][arr[i]]++;
        }
        sort(vc.begin(), vc.end());
        sort(vr.begin(), vr.end());
        for (int i = 0; i < vc.size(); i++) {
            printf("%d={", vc[i]);
            for (int j = 0; j < vr.size(); j++) {
                printf("%d=%d", vr[j], mp[vc[i]][vr[j]]);
                if (j != vr.size() - 1) printf(",");
                else printf("}\n");
            }
        }
    }
    return 0;    
}