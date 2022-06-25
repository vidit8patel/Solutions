class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        int count = 0;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                if(count++ || i > 1 && i < nums.size()-1 && nums[i-2] > nums[i] && nums[i-1] > nums[i+1])
                    return false;
            }
        }
        return true;
    }
};