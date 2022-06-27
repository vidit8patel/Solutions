class Solution {
public:
    int minPartitions(string n) {
        int ans = INT_MIN;
        for(auto ch : n)
        {
            int x = ch - '0';
            ans = max(ans, x);
        }
        return ans;
    }
};