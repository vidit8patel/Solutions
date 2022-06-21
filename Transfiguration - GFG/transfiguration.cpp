// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
        vector<int> v(128, 0);
        for(auto ch: A)
        {
            v[ch]++;
        }
        for(auto ch: B)
        {
            v[ch]--;
        }
        for(auto it: v)
        {
            if(it != 0)
                return -1;
        }
        int i = A.length(), j = B.length();
        int ans = 0;
        while(j >= 0 && i >= 0)
        {
            if(B[j] == A[i])
                {
                    i--;
                    j--;
                }
            else
            {
                while(i >= 0 && B[j] != A[i])
                {
                    i--;
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends