// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int eggDrop(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
    int solve(int k, int n) {
        if(n == 0 || n == 1)
            return n;
        if(k == 1)
            return n;
        if(dp[k][n] != -1)
            return dp[k][n];
        int ans = INT_MAX;
        for(int i = 1; i<=n; i++)
        {
            int temp = 1 + max(solve(k-1, i-1), solve(k, n-i));
            ans = min(ans, temp);
        }
        return dp[k][n] = ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends