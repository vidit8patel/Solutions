// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
	    vector<int> ans;
	    for(int i = 0; i<n; i++)
	    {
	        int row = i;
	        int col = 0;
	        while(row >= 0 && col < n)
	        {
	            ans.push_back(A[col++][row--]);
	        }
	    }
	    
	    for(int i = 1; i<n; i++)
	    {
	        int row = n-1;
	        int col = i;
	        while(row > 0 && col < n)
	        {
	            ans.push_back(A[col++][row--]);
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends