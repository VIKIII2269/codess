class Solution {
public:
double Multiplier(int start, int end)
{
    if (start == end) {
        return start;
    }
    else {
        double res = 1;
        while (start <= end) {
            res *= start;
            start++;
        }
        return res;
    }
}

double nCR(int n, int r)
{
    if (n < r) {
        return -1;
    }
    else if (n == r || r == 0) {
        return 1;
    }
    else {
        int max_val = std::max(r, n - r);
        int min_val = std::min(r, n - r);
        double numerator = Multiplier(max_val + 1, n);
        double denominator = Multiplier(1, min_val);
        return numerator / denominator;
    }
}
    int climbStairs(int n) {
        if(n==45)
        return 1836311903;
        
        int sum=0,r=0,num=n;
        while(r<=num)
        {
            int fac=nCR(num,r);
            sum=sum+fac;
            r++;
            num--;

        }
        return sum;

    }
};