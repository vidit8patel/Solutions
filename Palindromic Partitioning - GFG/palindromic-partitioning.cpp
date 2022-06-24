// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, str.length()-1);
    }
    int solve(string &str, int i, int j)
    {
        if(i >= j || isPalindrome(str, i, j))
            return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        int ans = INT_MAX, temp;
        for(int k = i; k <= j-1; k++)
        {
            temp = solve(str, i, k) + solve(str, k+1, j) + 1;
            ans = min(temp, ans);
        }
        return dp[i][j] = ans;
    }
    bool isPalindrome(string &str, int i, int j)
    {
        while(i < j)
        {
            if(str[i] != str[j])
                    return false;
                i++;
                j--;
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends