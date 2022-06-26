class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum = 0;
        for(int i = 0; i<k; i++)
            sum += a[i];
        int ans = sum;
        int i = k-1;
        for(int j = a.size()-1;; j--)
        {
            if(i>=0)
            {
                sum += a[j]-a[i];
                ans = max(ans, sum);
                i--;
            }
            else break;
        }
        return ans;
    }
};