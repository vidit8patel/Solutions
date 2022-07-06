class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans,vector<int>&sub)
    {
        ans.push_back(sub);
        for(int i = index; i< nums.size(); i++)
        {
            if(i == index || nums[i] != nums[i-1])
            {
                sub.push_back(nums[i]);
                solve(i+1, nums, ans, sub);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        solve(0, nums, ans, sub);
        return ans;
    }
};