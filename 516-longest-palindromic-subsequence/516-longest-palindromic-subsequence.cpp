class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        int dp[m+1][m+1];
        for(int i = 0; i<=m;i++)
        {
            for(int j = 0; j<=m; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s[i-1] == t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][m];
    }
};