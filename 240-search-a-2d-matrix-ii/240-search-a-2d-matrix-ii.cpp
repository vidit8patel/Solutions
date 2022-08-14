class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i<m; i++){
            int l=0, r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(matrix[i][mid]==target)
                    return true;
                if(matrix[i][mid]<target)
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return false;
    }
};


















// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = 0, col = matrix[0].size()-1;
//         while(row < matrix.size() && col >= 0)
//         {
//             if(matrix[row][col] == target)
//                 return true;
//             else if(matrix[row][col] > target)
//                 col--;
//             else row++;
//         }
//         return false;
//     }
// };