class Solution {
public:
    int dp[301][301];
    int ans = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                    ans = max(ans, solve(matrix, i, j, m, n));
            }
        }
        return ans*ans;
    }
    int solve(vector<vector<char>>& matrix, int i, int j, int m, int n)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = 1 + min(solve(matrix, i+1, j+1,m,n), min(solve(matrix,i+1, j, m, n), solve(matrix,i,j+1, m,n)));
    }
};
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         if(matrix.empty())
//             return 0;
//         int ans = 0;
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> grid(m, vector<int>(n,0));
//         for(int i = m-1; i>=0; i--)
//         {
//             if(matrix[i][n-1] == '1')
//             {
//                 grid[i][n-1] = 1;
//                 ans = 1;
//             }
//         }
//         for(int i = n-1; i>=0; i--)
//         {
//             if(matrix[m-1][i] == '1')
//             {
//                 grid[m-1][i] = 1;
//                 ans = 1;
//             }
//         }
//         for(int i = m-2; i>=0; i--)
//         {
//             for(int j = n-2; j>=0; j--)
//             {
//                 if(matrix[i][j] == '1')
//                 {
//                     grid[i][j] = min(grid[i+1][j+1], min(grid[i+1][j], grid[i][j+1])) + 1;
//                 }
//                 else grid[i][j] = 0;
//                 ans = max(ans, grid[i][j]);
//             }
//         }
//         return ans*ans;
//     }
// };