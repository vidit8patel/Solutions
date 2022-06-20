//O(N)
//O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        for(int i = 1; i<nums.size(); i++)
        {
            int temp = max(nums[i], max(minProd*nums[i], maxProd*nums[i]));
            minProd = min(nums[i], min(minProd*nums[i], maxProd*nums[i]));
            maxProd = temp;
            ans = max(maxProd, ans);
        }
        return ans;
    }
};