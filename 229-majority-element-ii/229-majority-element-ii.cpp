class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, num1, num2;
        for(int i = 0; i<nums.size(); i++)
        {
            if(num1 == nums[i])
            {
                count1++;
            }
            else if(num2 == nums[i])
            {
                count2++;
            }
            else if(count1 == 0)
            {
                num1 = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2++;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        vector<int> ans;
        for(auto num : nums)
        {
            if(num1 == num)
            {
                count1++;
            }
            else if(num2 == num)
            {
                count2++;
            }
        }
        if(count1 > nums.size()/3)
        {
            ans.push_back(num1);
        }
        if(count2 > nums.size()/3)
        {
            ans.push_back(num2);
        }
        return ans;
    }
};
