class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto x:stones)
        {
            sum += x;
        }
        int n = stones.size();
        bool dp[n+1][sum+1];
        for(int i = 0; i<=n; i++)
        {
            for(int j = 0; j<=sum; j++)
            {
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=sum; j++)
            {
                if(stones[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];    
                else dp[i][j] = dp[i-1][j];
            }
        }
                
        int ans = INT_MAX;
        for(int i = 0; i<=sum/2; i++)
        {
            if(dp[n][i] == true)
            {
                int x = sum - (2*i);
                ans = min(ans, x);
            }
        }
        return ans;
    }
};