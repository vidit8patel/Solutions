// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[51][51];
    int maxGold(int m, int n, vector<vector<int>> &M)
    {
        
            memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for(int i = 0; i<m; i++)
        {
            ans = max(ans, solve(i, 0, M, m, n));
        }
        return ans;
    }
    int solve(int i, int j, vector<vector<int>>& M, int m, int n)
    {
        if(i < 0 || i >= m)
            return 0;
        if(j == n-1)
            return M[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int a = 0, b = 0, c = 0;
        a = solve(i+1, j+1, M, m, n);
        b = solve(i-1, j+1, M, m, n);
        c = solve(i, j+1, M, m, n);
        return dp[i][j] = M[i][j] + max(a, max(b, c));
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends