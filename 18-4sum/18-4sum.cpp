class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(!nums.size())
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                int left = j+1;
                int right = nums.size()-1;
                long long sum = (long long)target - nums[i] - nums[j];
                while(left < right)
                {
                    if(nums[left] + nums[right] < sum)
                        left++;
                    else if(nums[left] + nums[right] > sum)
                        right--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        while(left < right && nums[left] == temp[2]) left++;
                        while(left < right && nums[right] == temp[3]) right--;
                    }

                }
                while(j+1 < nums.size() && nums[j+1] == nums[j]) j++;
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};