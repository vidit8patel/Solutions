class Solution {
public:
    int dp[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, grid.size()-1, grid[0].size()-1);
    }
    int solve(vector<vector<int>>&grid, int m, int n)
    {
        if(m < 0 || n < 0)
            return INT_MAX;
        if(m == 0 && n == 0)
            return grid[m][n];
        if(dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = grid[m][n] + min(solve(grid,m-1,n), solve(grid,m, n-1));
    }
};


// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid)
//     {
//         if(grid.empty())
//             return 0;
//         int m = grid.size();
//         int n =grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n));
        
//         dp[0][0]=grid[0][0];
        
//         for (int j=1;j<n;j++)
//         {
//             dp[0][j] = grid[0][j] + dp[0][j-1];
//         }
//         for (int i=1;i<m;i++)
//         {
//             dp[i][0] = grid[i][0] + dp[i-1][0];
//         }
//         for (int i=1;i<m;i++)
//         {
//             for (int j=1;j<n;j++)
//             {
//                   dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// }; 