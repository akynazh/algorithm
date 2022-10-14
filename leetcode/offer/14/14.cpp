#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int x = n / 3, y = n % 3;
        if (y == 0) return int(pow(3, x));
        else if (y == 1) return int(pow(3, x-1) * 4);
        else return int(pow(3, x) * 2);
    }
};
int main() {
    Solution solution;
    int ans = solution.cuttingRope(10);
    cout << ans << endl;
    return 0;
}
