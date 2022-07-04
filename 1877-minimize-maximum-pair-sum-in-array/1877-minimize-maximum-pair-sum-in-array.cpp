class Solution {
public:
    int minPairSum(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        int ans = 0, n = A.size();
        for (int i = 0; i < n / 2; ++i)
            ans = max(ans, A[i] + A[n - i - 1]);
        return ans;
    }
};