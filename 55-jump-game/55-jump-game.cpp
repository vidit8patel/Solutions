class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(i > reachable)
                return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& A) {
//         int i = 0;
//         int reach = 0;
//         for (; i < A.size() && i <= reach; ++i)
//             reach = max(i + A[i], reach);
//         return i == A.size();
//     }
// };