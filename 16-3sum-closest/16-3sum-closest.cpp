class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return 0;
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int first = 0; first < nums.size()-2; first++)
        {
            if(first > 0 && nums[first] == nums[first-1])
                continue;
            int second = first + 1, third = nums.size()-1;
            while(second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];
                if(abs(target - sum) < abs(target - ans))
                    ans = sum;
                if(sum > target)
                    third--;
                else second++;
            }
        }
        return ans;
    }
};