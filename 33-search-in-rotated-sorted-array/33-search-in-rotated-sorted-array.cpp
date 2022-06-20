//O(logN)
//O(1)
class Solution {
public:
    int search(vector<int>& A, int key)
    {
        int l = 0, h = A.size()-1;
       while(l <= h)
        {
            int mid = (l + h)/2;
            
            if(A[mid] == key)
                return mid;
            
            if(A[l] <= A[mid])
            {
                if(key >= A[l] && key < A[mid])
                    h = mid -1;
                else 
                    l = mid +1;
            }
            
            else 
            {
                if(key <= A[h] && key > A[mid])
                    l = mid +1;
                else 
                    h = mid -1;
            }
            
        }
        
        return -1;
 
    }
};