#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, arr[110], num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                num++; 
            }
        }
    }
    cout << num;
    return 0;
}