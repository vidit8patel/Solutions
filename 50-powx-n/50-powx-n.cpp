class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long neg = n;
        if(n < 0)
            neg *= -1;
        while(neg > 0)
        {
            if(neg%2 == 0)
            {
                x *= x;
                neg /= 2;
            }
            else 
            {
                ans *= x;
                neg--;
            }
        }
        if(n < 0)
            return double(1)/double(ans);
        return ans;
    }
};