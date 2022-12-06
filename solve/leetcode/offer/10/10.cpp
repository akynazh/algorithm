#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        int F[110];
        const int m = 1000000007;
        F[0] = 0; F[1] = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 2; i <= n; i++) {
            F[i] = F[i-1] % m + F[i-2] % m;
            F[i] %= m;
        } 
        return F[n] % m;
    }
};
int main() {
    Solution solution;
    int n;
    cin >> n;
    printf("%d\n", solution.fib(n));
    return 0;
}