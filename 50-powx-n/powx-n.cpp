class Solution {
public:
    double myPow(double x, int p) {
        long long n=p;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        if (n == 0) {
            return 1.0;
        }

        double temp = myPow(x, n / 2);
        temp = temp * temp;

        if (n % 2 == 0) {
            return temp;
        } else {
            return temp * x;
        }
    }
};
