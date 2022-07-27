class Solution {
public:
    int dp[302][302];
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<int> newNums(nums.size()+2, 1);
        int x = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            newNums[x++] = nums[i];
        }
        return solve(newNums, 0, newNums.size()-1);
    }
    int solve(vector<int> &newNums, int left, int right)
    {
        if(left+1 == right)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        int ans = 0;
        for(int i = left+1; i<right; i++)
        {
            ans = max(ans, newNums[left] * newNums[i] * newNums[right] + solve(newNums, left, i) + solve(newNums, i, right));
        }
        return dp[left][right] = ans;
    }
};