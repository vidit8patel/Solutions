class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int start = 0;
        int end = nums.size()-1;
        res.push_back(-1);
        res.push_back(-1);
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(target == nums[mid])
            {
                res[0] = mid;
                end = mid-1;
            }
            else if(target>nums[mid])
                start = mid+1;
            else end = mid-1;
        } 
        start = 0;
        end = nums.size()-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(target == nums[mid])
            {
                res[1] = mid;
                start = mid+1;
            }
            else if(target>nums[mid])
                start = mid+1;
            else end = mid-1;
        }
        
        return res;
    }
};