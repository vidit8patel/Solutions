// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int m = wild.length(), n = pattern.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        for(int i = m; i>=0; i--)
        {
            for(int j = n; j>=0; j--)
            {
                if(i == m && j == n)
                    dp[i][j] = true;
                else if(i == m)
                    dp[i][j] = false;
                else if(j == n)
                {
                    if(wild[i] == '*')
                        dp[i][j] = dp[i+1][j];
                    else dp[i][j] = false;
                }
                else if((wild[i] == '?') || wild[i] == pattern[j])
                    dp[i][j] = dp[i+1][j+1];
                else if(wild[i] == '*')
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends