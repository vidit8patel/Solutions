class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(countLessOrEqual(matrix, mid, m, n) >= k)
            {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return ans;
    }
    int countLessOrEqual(vector<vector<int>>& matrix, int x, int m, int n)
    {
        int count = 0, c = n-1;
        for(int r = 0; r<m; r++)
        {
            while(c>=0 && matrix[r][c] > x) c--;
            count += (c+1);
        }
        return count;
    }
};