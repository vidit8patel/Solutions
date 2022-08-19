class Solution {
public:
    int dp[100001][4];
    int solve(int idx, int trans, vector<int>& prices)
    {
        if(idx == prices.size() || trans == 4)
            return 0;
        if(dp[idx][trans] != -1)
            return dp[idx][trans];
        if(trans % 2 == 0)
        {
            return dp[idx][trans] = max(-prices[idx] + solve(idx+1, trans+1, prices),
                0 + solve(idx + 1, trans, prices));
        }
        else 
            return dp[idx][trans] = max(prices[idx] + solve(idx + 1, trans + 1, prices),
                0 + solve(idx + 1, trans, prices));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }
};