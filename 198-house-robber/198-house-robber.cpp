class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
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

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int include = 0, exclude = 0;
//         for(int i = 0; i<nums.size(); i++)
//         {
//             int x = nums[i] + exclude;
//             int y = max(include,exclude);
//             include = x;
//             exclude = y;
//         }
//         return max(include, exclude);
//     }
// };