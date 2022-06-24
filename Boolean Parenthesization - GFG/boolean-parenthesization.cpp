// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int countWays(int N, string s){
        memset(dp, -1, sizeof(dp));
        return solve(0, N-1, s, 1);
    }
    int solve(int i, int j, string s, bool isTrue)
    {
        if(i > j)
            return 0;
        if(i == j)
        {
            if(isTrue == true)
                return s[i] == 'T';
            else return s[i] == 'F';
        }
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ans = 0;
        for(int k = i+1; k<=j-1; k+=2)
        {
            int lt, lf, rt, rf;
            
            
            if(dp[i][k-1][1] != -1)
                lt = dp[i][k-1][1];
            else lt = dp[i][k-1][1] = solve(i, k-1, s, 1);
            
            if(dp[i][k-1][0] != -1)
                lf = dp[i][k-1][0];
            else lf = dp[i][k-1][0] = solve(i, k-1, s, 0);
            
            if(dp[k+1][j][1] != -1)
                rt = dp[k+1][j][1];
            else rt = dp[k+1][j][1] = solve(k+1, j, s, 1);
            
            if(dp[k+1][j][0] != -1)
                rf = dp[k+1][j][0];
            else rf = dp[k+1][j][0] = solve(k+1, j, s, 0);
            
            
            if(s[k] == '&')
            {
                if(isTrue == true)
                {
                    ans += lt*rt;
                }
                else ans += lt*rf + lf*rt + lf*rf;
            }
            else if(s[k] == '|')
            {
                if(isTrue == true)
                {
                    ans += lt*rf + lf*rt + lt*rt;
                }
                else ans += lf*rf;
            }
            if(s[k] == '^')
            {
                if(isTrue == true)
                {
                    ans += lt*rf + lf*rt;
                }
                else ans += lt*rt + lf*rf;
            }
        }
        return dp[i][j][isTrue] = ans%1003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends