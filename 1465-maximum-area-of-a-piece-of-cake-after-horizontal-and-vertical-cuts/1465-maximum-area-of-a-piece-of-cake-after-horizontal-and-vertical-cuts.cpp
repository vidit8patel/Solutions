class Solution {
public:
    int maxArea(int h, int w, vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int maxH = max(A[0], h-A.back());
        int maxV = max(B[0], w-B.back());
        for(int i = 1; i<A.size(); i++)
        {
            maxH = max(maxH, A[i]-A[i-1]);
        }
        for(int i = 1; i<B.size(); i++)
        {
            maxV = max(maxV, B[i]-B[i-1]);
        }
        return (long)maxH*maxV%1000000007;
    }
};