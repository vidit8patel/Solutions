class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] >= nums[0])
            {
                l = mid+1;
            }
            else 
                r = mid;
        }
        if(l == nums.size()-1 && nums[l] > nums[0])
            return nums[0];
        return nums[l];
    }
};