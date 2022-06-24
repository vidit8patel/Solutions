class Solution {
public:
    int dp[101][10001];
    int superEggDrop(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(k,n);
    }
    int solve(int k, int n) {
        if(n == 0 || n == 1)
            return n;
        if(k == 1)
            return n;
        if(dp[k][n] != -1)
            return dp[k][n];
        int ans = INT_MAX;        
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int left = solve(k - 1, mid - 1);
            int right = solve(k, n - mid);
            ans = min(ans, 1+max(left, right));
            if (left == right) 
            {
                break;
            } 
            else if (left < right) 
            {
                low = mid + 1;
            } 
            else 
            {
                high = mid;
            }
        }

        return dp[k][n] = ans;
    }
};

// class Solution {
// public:
//     int dp[101][10001];
//     int superEggDrop(int k, int n)
//     {
//         memset(dp, -1, sizeof(dp));
//         return solve(k,n);
//     }
//     int solve(int k, int n) {
//         if(n == 0 || n == 1)
//             return n;
//         if(k == 1)
//             return n;
//         if(dp[k][n] != -1)
//             return dp[k][n];
//         int ans = INT_MAX;
//         for(int i = 1; i<=n; i++)
//         {
//             int temp = 1 + max(solve(k-1, i-1), solve(k, n-i));
//             ans = min(ans, temp);
//         }
//         return dp[k][n] = ans;
//     }
// };