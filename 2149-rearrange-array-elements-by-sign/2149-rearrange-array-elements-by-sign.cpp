class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int idx1 = 0, idx2 = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] >= 0)
            {
                ans[idx1] = nums[i];
                idx1+=2;
            }
            else
            {
                ans[idx2] = nums[i];
                idx2+=2;
            }
        }
        return ans;
    }
};