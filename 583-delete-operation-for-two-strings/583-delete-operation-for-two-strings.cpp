class Solution {
public:    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i = 0; i<=m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if(text1[i-1] == text2[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) 
    {
        return word1.length() + word2.length() - 2*longestCommonSubsequence(word1, word2);
    }
};