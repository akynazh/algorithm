#include <bits/stdc++.h>
using namespace std;
int n, arr[110];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int piv = arr[0];
    int l = 0, r = n - 1;
    while (l < r) {
        while (l < r && arr[r] >= piv) r--;
        arr[l] = arr[r];
        while (l < r && arr[l] <= piv) l++;
        arr[r] = arr[l];
    }
    arr[l] = piv;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}