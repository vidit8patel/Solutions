class Solution {
public:
    int dp[13][10001];

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, 0, amount);;
        return ans == INT_MAX-1 ? -1 : ans;
    }
    int solve(vector<int>& coins, int i, int amount)
    {
        if(amount <= 0 || i == coins.size())
            {
                if(amount == 0)
                    return 0;
                return INT_MAX-1;
            }
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int ans;
        if(coins[i] > amount)
        {
            int donottake = 0 + solve(coins, i+1, amount-0);
            dp[i][amount] = ans = donottake;
        }
        else
        {
            int take = 1 + solve(coins, i, amount - coins[i]);
            int donottake = 0 + solve(coins, i+1, amount - 0);
            dp[i][amount] = ans = min(take, donottake);
        }
        return dp[i][amount] = ans;
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0)
//             return 0;
//         vector<int> dp(amount+1, amount+1);
//         dp[0] = 0;
//         for(int i = 1; i<dp.size(); i++)
//         {
//             for(int j = 0; j<coins.size(); j++)
//             {
//                 if(i - coins[j] >= 0)
//                     dp[i] = min(dp[i], 1+dp[i-coins[j]]);
//             }
//         }
//         if(dp[amount] > amount)
//             return -1;
//         return dp[amount];
//     }
// };