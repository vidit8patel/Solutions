// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int nums[], int n, int k)
	{
	    int ans = 0, sum = 0;
	    unordered_map<int, int> map;
	    for(int i = 0; i<n; i++)
	    {
	        sum += nums[i];
	        int mod = ((sum%k)+k)%k;
	        if(mod == 0)
	            ans = i+1;
	        else if(map.find(mod) != map.end())
	        {
	            ans = max(ans, i-map[mod]);
	        }
	        else
	        map[mod] = i;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends