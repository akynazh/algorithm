对一个升序排序的字符串数组，以最小的增长量最大字符串，可以得到字符串所有可能的排序情况。

```java
public boolean nextPermutation(char[] arr) {
    int i = arr.length - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--; // 找到尽可能靠右的较小者
    if (i < 0) return false;
    int j = arr.length - 1; // 找到尽可能小的较大者
    while (j >= 0 && arr[i] >= arr[j]) j--;
    // 交换较小者和较大者
    swap(arr, i, j);
    // 将较大者之后的数据串反转
    int left = i + 1, right = arr.length - 1;
    while (left < right) {
        swap(arr, left, right);
        left++;
        right--;
    }
    return true;
}

public void swap(char[] arr, int i, int j) {
    char tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
```