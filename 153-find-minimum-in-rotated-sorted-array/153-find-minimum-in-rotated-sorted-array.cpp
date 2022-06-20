class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(nums[l] <= nums[r])
            return nums[l];
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[mid+1])
            {
                return nums[mid+1];
            }
            if(nums[mid] > nums[l])
                l = mid+1;
            else 
                r = mid;
        }
        return nums[0];
    }
};