class Solution {
public:
    int dp[101][101][201];
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n1 + n2 != n3)
            return false;
        memset(dp, -1, sizeof(dp));
        return solve(s1, 0, n1, s2, 0, n2, s3, 0, n3);
    }
    bool solve(string s1, int i1, int n1, string s2, int i2, int n2, string s3, int i3, int n3)
    {
        if(i1 == n1 && i2 == n2 && i3 == n3)
            return true;
        if(dp[i1][i2][i3] != -1)
            return dp[i1][i2][i3];
        if(i1 < n1 && s1[i1] == s3[i3] && solve(s1, i1 + 1, n1, s2, i2, n2, s3, i3+1, n3))
            return dp[i1][i2][i3] = true;
        if(i2 < n2 && s2[i2] == s3[i3] && solve(s1, i1, n1, s2, i2+1, n2, s3, i3+1, n3))
            return dp[i1][i2][i3] = true;
        else return dp[i1][i2][i3] = false;
            
    }
};