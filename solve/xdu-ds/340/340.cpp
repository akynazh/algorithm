#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, arr[110];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int inc = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + inc; j < n; j += inc) {
            if (arr[j] < arr[j-inc]) {
                int temp = arr[j];
                arr[j] = arr[j-inc];
                arr[j-inc] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}