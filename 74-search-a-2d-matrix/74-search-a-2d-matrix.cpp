class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), beg = 0;
        int end = row*col - 1;
        while(beg <= end)
        {
            int mid = (beg+end)/2;
            if(target == matrix[mid/col][mid%col])
                return true;
            else if(target > matrix[mid/col][mid%col])
                beg = mid+1;
            else end = mid-1;
        }
        return false;
    }
};