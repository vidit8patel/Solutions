class Solution {
public:
    bool seen[50001];
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size())
            return false;
        if(seen[start])
            return false;
        if(arr[start] == 0)
            return true;
        seen[start] = 1;
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};