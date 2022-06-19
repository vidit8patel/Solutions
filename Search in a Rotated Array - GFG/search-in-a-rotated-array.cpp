// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    //O(logN)
    //O(1)
    public:
    int findPivot(int nums[], int l, int h)
    {
        while(l < h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] >= nums[0])
                l = mid + 1;
            else h = mid;
        }
        return l;
    }
    int bSearch(int nums[], int l, int h, int key)
    {
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] == key)
                return mid;
            else if(nums[mid] > key)
                h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
    int search(int A[], int l, int h, int key){
    //complete the function here
    int pivot = findPivot(A, l, h);
    if(A[pivot] <= key && A[h] >= key)
        return bSearch(A, pivot, h, key);
    return bSearch(A, l, pivot-1, key);
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends