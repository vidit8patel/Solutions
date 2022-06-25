class Solution {
public:
    int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> set(days.begin(), days.end());
        memset(dp, -1, sizeof(dp));
        return solve(set, costs, 1);
    }
    int solve(unordered_set<int>& set, vector<int>& costs, int index)
    {
        if(index > 365)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int ans = INT_MAX;
        if(set.find(index) != set.end())
        {
            ans = min(ans, min(costs[0] + solve(set, costs, index+1), min(costs[1] + solve(set,costs, index+7), costs[2] + solve(set, costs, index+30))));
        }
        else
            ans = solve(set, costs, index+1);
        return dp[index] = ans;
    }
};