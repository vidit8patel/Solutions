// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)
//             return 1;
//         vector<int> dp(nums.size(), 1);
//         int ans = INT_MIN;
//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(nums[i] - nums[j] > 0)
//                 {
//                     dp[i] = max(dp[i], 1+dp[j]);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }
//         return ans;
//     }
// };

class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            vector<int> arr;
            for (auto num: nums)
            {
                if (arr.size() == 0 || num > arr[arr.size() - 1])
                    arr.push_back(num);
                else
                {
                    auto it = lower_bound(arr.begin(), arr.end(), num);
                    int index = it - arr.begin();
                    arr[index] = num;
                }
            }
            return arr.size();
        }
};