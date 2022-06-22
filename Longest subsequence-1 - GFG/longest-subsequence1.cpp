// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        int dp[N];
        int ans = INT_MIN;
        dp[0] = 1;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(abs(A[i] - A[j]) == 1)
                {
                    dp[i] = max(dp[i],dp[j]);
                }
            }
            dp[i] += 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends