class Solution {
public:
    int dp[10001];
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
    int solve(int n)
    {
        if(sqrt(n) - floor(sqrt(n)) == 0)
            return 1;
        if(n < 4)
            return n;
        if(dp[n] != -1)
            return dp[n];
        int ans = n;
        for(int i = 1; i<=n; i++)
        {
            int temp = i*i;
            if(temp > n)
                break;
            else ans = min(ans, 1 + solve(n-temp));
        }
        return dp[n] = ans;
    }
};