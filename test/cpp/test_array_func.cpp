#include <bits/stdc++.h>
using namespace std;

const int ARR_LEN = 100;

// ok
void test_arr_1(int* arr) { arr[0] = 91; }

// other
void test_arr_2(int (&arr)[ARR_LEN]) { arr[0] = 92; }
void test_arr_3(int arr[]) { arr[0] = 93; }
void test_a_1(int* a) { *a = 3; }

// ok
void test_a_2(int& a) { a = 93; }

int main() {
    int arr[ARR_LEN];
    memset(&arr, -1, sizeof(arr));
    test_arr_1(arr);
    cout << arr[0] << endl;
    test_arr_2(arr);
    cout << arr[0] << endl;
    test_arr_3(arr);
    cout << arr[0] << endl;

    // int a = 10;
    // test_a_1(&a);
    // cout << a << endl;
    // test_a_2(a);
    // cout << a << endl;
    return 0;
}
