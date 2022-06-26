class Solution {
public:
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict, 0);
    }
    bool solve(string s, unordered_set<string>& dict, int index)
    {
        if(index == s.length())
            return true;
        if(dp[index] != -1)
            return dp[index];
        string sub;
        for(int i = index; i<s.length(); i++)
        {
            if(dict.count(sub += s[i]))
            {
                if(dp[i+1] == -1) 
                    dp[i+1] = solve(s, dict, i+1);
                if(dp[i+1] == true)
                    return true;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         if(wordDict.size() == 0)
//             return false;
//         int n = s.length();
//         vector<bool> dp(n+1, false);
//         dp[0] = true;
//         for(int i = 1; i<=n; i++)
//         {
//             for(int j = i-1; j>=0; j--)
//             {
//                 if(dp[j] == true)
//                 {
//                     string word = s.substr(j, i-j);
//                     for(int z = 0; z<wordDict.size(); z++)
//                     {
//                         if(word == wordDict[z])
//                         {
//                             dp[i] = true;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[n];
//     }
// };