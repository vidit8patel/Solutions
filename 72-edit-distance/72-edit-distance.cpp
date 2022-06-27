class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, word1.length(), word2.length());
    }
    int solve(string word1, string word2, int i, int j)
    {
        if(i == 0 || j == 0)
            return max(i, j);
        if(dp[i][j] != -1)
            return dp[i][j];
        if(word1[i-1] == word2[j-1])
            return dp[i][j] = solve(word1, word2, i-1, j-1);
        else
        {
            int a, b, c;
            if(dp[i-1][j] != -1)
                a = dp[i-1][j];
            else dp[i-1][j] = a = solve(word1,word2, i-1, j);
            if(dp[i-1][j-1] != -1)
                b = dp[i-1][j-1];
            else dp[i-1][j-1] = b = solve(word1,word2, i-1, j-1);
            if(dp[i][j-1] != -1)
                c = dp[i][j-1];
            else dp[i][j-1] = c = solve(word1,word2, i, j-1);
            return dp[i][j] = min(a, min(b,c)) + 1;
        }
    }
};

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         int dp[m+1][n+1];
//         for(int i = 0; i<=m; i++)
//         {
//             dp[i][0] = i;
//         }
//         for(int i = 0; i<=n; i++)
//         {
//             dp[0][i] = i;
//         }
//         for(int i = 1; i<=m; i++)
//         {
//             for(int j = 1; j<=n; j++)
//             {
//                 if(word1[m-i] == word2[n-j])
//                 {
//                     dp[i][j] = dp[i-1][j-1];
//                 }
//                 else
//                 {
//                     int a = dp[i-1][j];
//                     int b = dp[i][j-1];
//                     int c = dp[i-1][j-1];
//                     dp[i][j] = min(a, min(b,c)) + 1;
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };