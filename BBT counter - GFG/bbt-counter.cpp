// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long dp[1005] = {-1};
    long long mod = 1e9+7;
    long long int countBT(int h) { 
        // code here
        if(h <= 1)
        return 1;
        if(dp[h] != 0)
            return dp[h]; 
        return dp[h] = (countBT(h-1)*(countBT(h-1) + (2*countBT(h-2))%mod)%mod)%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends