class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        memset(dp, -1, sizeof(dp));
        vector<int> A(nums.begin(), nums.end()-1);
        int ans1 = solve(A, 0);
        memset(dp, -1, sizeof(dp));        
        vector<int> B(nums.begin()+1, nums.end());
        return max(ans1, solve(B, 0));
    }
    int solve(vector<int>&nums, int index)
    {
        if(index >= nums.size())
            return 0;
        if(dp[index] != -1)
            return dp[index];
        return dp[index] = max(solve(nums, index+1), solve(nums, index+2) + nums[index]);
    }
};