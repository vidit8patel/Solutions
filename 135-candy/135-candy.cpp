class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size();
        if(n<2)
            return n;
        vector<int> nums(n, 1);
        for(int i = 1; i<n; i++)
        {
            if(A[i] > A[i-1])
                nums[i] = nums[i-1]+1;
        }
        for(int i = n-1; i>0; i--)
        {
            if(A[i-1] > A[i])
                nums[i-1] = max(nums[i]+1,nums[i-1]);
        }
        int ans =0;
        for (int i = 0; i < n; i++)
            ans += nums[i];
        
        return ans;
    }
};