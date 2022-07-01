class Solution {
public:
    char dp[21][31];
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, 0, 0);
    }
    bool solve(string s, string p, int i, int j)
    {
        if(p.length() == j)
            return dp[i][j] = i == s.length();
        if(dp[i][j] != -1)
            return dp[i][j];
        if(p.length() > j+1 && p[j+1] == '*')
        {
            if(solve(s, p, i, j+2))
                return dp[i][j] = true;
            if(s.length() > i && (p[j] == '.' || s[i] == p[j]))
                return dp[i][j] = solve(s, p, i+1, j);
            return dp[i][j] = false;
        }
        else
        {
            if(s.length() >i && (p[j] == '.' || s[i] == p[j]))
            {
                return dp[i][j] = solve(s, p, i+1, j+1);
            }
        }
        return dp[i][j] = false;
    }
};

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.length(), n = p.length();
//         vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
//         dp[m][n] = true;
//         for(int i = s.length(); i>=0; i--)
//         {
//             for(int j = p.length()-1; j>=0; j--)
//             {
//                 bool firstMatch = (i<s.length()) && (p[j] == s[i] || p[j] == '.');
//                 if(j + 1 < p.length() && p[j+1] == '*')
//                 {
//                     dp[i][j] = dp[i][j+2] || firstMatch && dp[i+1][j];
//                 }
//                 else
//                     dp[i][j] = firstMatch && dp[i+1][j+1];
//             }
//         }
//         return dp[0][0];
//     }
// };