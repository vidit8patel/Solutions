class Solution {
public:
    void solve(int index, vector<int>nums, vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++)
        {
            if(i != index && nums[i] == nums[index])
                continue;
            swap(nums[index], nums[i]);
            solve(index+1, nums, ans);  
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};