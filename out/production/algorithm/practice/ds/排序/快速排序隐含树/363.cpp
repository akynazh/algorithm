#include <bits/stdc++.h>
using namespace std;
int n, arr[10000];
int part(int low, int high) {
    int piv = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= piv) high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= piv) low++;
        arr[high] = arr[low];
    }
    arr[low] = piv;
    return low;
}
void qsort(int low, int high) {
    int piv = part(low, high);
    if (piv - 1 >= low) qsort(low, piv - 1);
    if (piv + 1 <= high) qsort(piv + 1, high);
    printf("%d ", arr[piv]);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    qsort(0, n-1);
    return 0;
}