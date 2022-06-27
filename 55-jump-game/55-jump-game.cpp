class Solution {
public:
    int dp[10001];
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
    bool solve(vector<int>&nums, int i)
    {
        if(i >= nums.size()-1)
        {
            return true;
        }
        if(dp[i] != -1)
            return dp[i];
        int reach = i + nums[i];
        for(int k = i+1; k<=reach; k++)
        {
            if(solve(nums, k))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
};