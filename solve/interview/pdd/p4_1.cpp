#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000;
double get_num(double num) {
    double num_int = int(num);
    if (num - num_int < 0.5) {
        return num_int;
    } else {
        return num_int + 1;
    }
}
int main() {
    int N;
    double mr[MAX_N], pre_avg[MAX_N], pre_mid[MAX_N];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> mr[i];
    pre_avg[0] = mr[0], pre_mid[0] = mr[0];
    for (int i = 1; i < N; i++) {
        pre_avg[i] = (pre_avg[i-1] * i + mr[i])/ (i + 1);
        if ((i + 1) % 2) {
            pre_mid[i] = mr[(i + 1) / 2];
        } else {
            pre_mid[i] = (mr[(i + 1) / 2 - 1] + mr[(i + 1) / 2]) / 2;
        }
    }
    for (int i = 0; i < N; i++) cout << int(get_num(pre_avg[i])) << " ";
    cout << endl;
    for (int i = 0; i < N; i++) cout << int(get_num(pre_mid[i])) << " ";
    return 0;
}