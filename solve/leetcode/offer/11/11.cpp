#include <bits/stdc++.h>
using namespace std;
class Solution {
    const int m = 1000000007;

   public:
    int numWays(int n) {
        int f2 = 0, f1 = 1, fn;
        if (n == 0) return 1;
        for (int i = 0; i < n; i++) {
            fn = f2 % m + f1 % m;
            f2 = f1 % m;
            f1 = fn % m;
        }
        return fn % m;
    }
};
int main() {
    int n;
    cin >> n;

    Solution solution;
    int k = solution.numWays(n);
    cout << k;
    return 0;
}