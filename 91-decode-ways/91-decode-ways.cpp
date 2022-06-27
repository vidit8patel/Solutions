class Solution {
public:
    int dp[101];
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
    int solve(string s, int idx)
    {
        if(idx == s.length())
            return 1;
        if(dp[idx] != -1)
            return dp[idx];
        int ans = 0;
        if(s[idx] != '0')
            ans += solve(s, idx+1);
        if(idx+1 < s.length() && (s[idx] == '1' || s[idx] == '2' && (s[idx+1] < '7')))
            ans += solve(s, idx+2);
        return dp[idx] = ans;
    }
};

// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s[0] == '0')
//             return 0;
//         int n = s.length();
//         vector<int> dp(n+1, 0);
//         dp[0] = dp[1] = 1;
//         for(int i = 2; i<=n; i++)
//         {
//             int onedigit = s[i-1] - '0';
//             int twodigit = (s[i-2]-'0')*10 + onedigit;
//             if(onedigit>0)
//                 dp[i] += dp[i-1];
//             if(twodigit > 9 && twodigit <= 26)
//                 dp[i] += dp[i-2];
//         }
//         return dp[n];
//     }
// };