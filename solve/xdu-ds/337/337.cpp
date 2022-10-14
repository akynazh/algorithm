#include <bits/stdc++.h>
using namespace std;
int main() {
    int len, m, n, arr[210];
    cin >> m >> n;
    len = m + n;
    for (int i = 0; i < len; i++) cin >> arr[i];
    sort(arr, arr+len);
    for (int i = 0; i < len; i++) cout << arr[i] << " "; 
}