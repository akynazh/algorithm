#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, arr[110];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i <= 3; i++) {
        int k = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] > k) {
                for (int t = i; t > j; t--) arr[t] = arr[t-1];
                arr[j] = k;
                break;
            }
        }
        for (int u = 0; u < n; u++) cout << arr[u] << " ";
        cout << endl;
    }
}