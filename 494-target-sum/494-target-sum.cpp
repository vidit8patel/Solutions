class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long sum = 0;
        for(auto num : nums)
            sum += num;
        if(abs(target) > sum || (sum+target)%2 != 0)
            return 0;
        int x = (sum+target)/2;
        return subsetcount(nums, x);
    }
    int subsetcount(vector<int>& nums, int target)
    {
        int n = nums.size();
        int dp[n+1][target+1];
        for(int i = 0; i <= target; i++)
        {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j<=target; j++)
            {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};