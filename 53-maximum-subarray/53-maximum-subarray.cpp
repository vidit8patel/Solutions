//O(N)
//O(1)
class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int curr = 0, m = nums[0];
        for(int i = 0; i<nums.size(); i++)
        {
            curr += nums[i];
            m = max(m, curr);
            if(curr < 0)
                curr = 0;
        }
        return m;
    }
};