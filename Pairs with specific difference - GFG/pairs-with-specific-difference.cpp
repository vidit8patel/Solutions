// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        vector<int> dp(N+1, 0);
        dp[0] = 0;
        sort(arr, arr+N);
        for(int i = 1; i<=N; i++)
        {
            dp[i] = dp[i-1];
            if(arr[i] - arr[i-1] < K)
            {
                if(i >= 2)
                    dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
                else dp[i] = arr[i] + arr[i-1];
            }
        }
        return dp[N-1];   
    }
    //     {
    //     int maxSum = 0;
     
    //     // Sort elements to ensure every i and i-1 is closest
    //     // possible pair
    //     sort(arr, arr + N);
     
    //     // To get maximum possible sum,
    //     // iterate from largest to
    //     // smallest, giving larger
    //     // numbers priority over smaller
    //     // numbers.
    //     for (int i = N - 1; i > 0; --i)
    //     {
    //         // Case I: Diff of arr[i] and arr[i-1]
    //         //  is less than K,add to maxSum      
    //         // Case II: Diff between arr[i] and arr[i-1] is not
    //         // less than K, move to next i since with
    //         // sorting we know, arr[i]-arr[i-1] <
    //         // rr[i]-arr[i-2] and so on.
    //         if (arr[i] - arr[i - 1] < k)
    //         {
    //             // Assuming only positive numbers.
    //             maxSum += arr[i];
    //             maxSum += arr[i - 1];
     
    //             // When a match is found skip this pair
    //             --i;
    //         }
    //     }
     
    //     return maxSum;
    // }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends