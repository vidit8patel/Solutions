class Solution {
public:
    int dp[101][101][601];
    int solve(vector<pair<int, int>>& p, int m, int n, int idx)
    {
        if(idx == p.size() || (m == 0 && n == 0))
            return 0;
        if(p[idx].first > m || p[idx].second > n)
            return solve(p, m, n, idx+1);
        if(dp[m][n][idx] != -1)
            return dp[m][n][idx];
        int take = 1 + solve(p, m-p[idx].first, n-p[idx].second, idx+1);
        int donttake = solve(p, m, n, idx+1);
        return dp[m][n][idx] = max(take, donttake);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> p;
        memset(dp, -1, sizeof(dp));
        for(auto i: strs)
        {
            int z = 0, o = 0;
            for(auto ch : i)
            {
                if(ch == '1')
                    o++;
                else z++;
            }
            p.push_back({z, o});
        }
        return solve(p, m, n, 0);
    }
};