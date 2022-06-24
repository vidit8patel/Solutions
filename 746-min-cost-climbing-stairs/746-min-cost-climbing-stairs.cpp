class Solution {
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(solve(cost, cost.size()-1), solve(cost, cost.size()-2));
    }
    int solve(vector<int>&cost, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0||n == 1)
            return dp[n] = cost[n];
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    }
};