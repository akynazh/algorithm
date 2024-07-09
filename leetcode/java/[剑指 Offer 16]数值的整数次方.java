class Solution {
    public double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0 || x == 1) return x;
        if (x == -1) return n % 2 == 0 ? 1 : -1;
        double res = 1.0;
        long n1 = n;
        if (n1 < 0) {
            n1 = -n1;
            x = 1 / x;
        }
        while (n1 != 0) {
            if ((n1 & 1) != 0) {
                res = res * x;
            }
            n1 >>= 1;
            x = x * x;
        }
        return res;
    }
}

//runtime:0 ms
//memory:40.7 MB
