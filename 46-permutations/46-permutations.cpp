class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            backtrack(index+1,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
};