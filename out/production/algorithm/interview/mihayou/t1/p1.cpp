#include <bits/stdc++.h>
using namespace std;

int main() {
    long a, b, c, ssum = 0;
    cin >> a >> b >> c;
    long x = a / 2, y = b / 2, x1, y1;
    if (x != 0 && y != 0) {
        if (x >= y) {
            ssum += y;
            x1 = a - 2 * y;
            y1 = b - 2 * y;
        } else {
            ssum += x;
            x1 = a - 2 * x;
            y1 = b - 2 * x;
        }
    } else {
        x1 = x;
        y1 = y;
    }
    if (x1 + y1 + c < 4) cout << ssum;
    else cout << ssum + 1 + (c - (4 - x1 - y1)) / 4;
    
    return 0;
}
