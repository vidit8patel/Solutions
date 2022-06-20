class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2, j = n-1;
        for(; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i >= 0)
        {
            for(; j>=0; j--)
            {
                if(nums[j] > nums[i])
                {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};