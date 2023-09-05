#include <bits/stdc++.h>
using namespace std;
int arr[110], n;
void small_heap(int pa) {
    int temp = arr[pa];
    for (int i = 2 * pa; i <= n; i *= 2) {
        if (i + 1 <= n && arr[i+1] < arr[i]) i++;
        if (arr[i] > temp) break;
        arr[pa] = arr[i];
        pa = i; 
    }
    arr[pa] = temp;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for (int i = n / 2; i >= 1; i--) {
        small_heap(i);
    }
    for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
    return 0;
}