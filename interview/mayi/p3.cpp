#include <bits/stdc++.h>
using namespace std;
const int mmod = 1e9 + 7;

int main() {
    int n, arr[1000000 + 1], ssum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    do {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] * arr[i + 1] % 2) ssum = (ssum + 1) % mmod;
        }
    } while (next_permutation(arr, arr + n));
    cout << ssum % mmod;
    return 0;
}
