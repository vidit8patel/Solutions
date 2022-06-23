class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i = 0; i<=amount; i++)
        {
            dp[0][i] = INT_MAX-1;
        }
        for(int i = 1; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 1; j<=amount; j++)
        {
            if(j%coins[0] == 0)
                dp[1][j] = j/coins[0];
            else dp[1][j] = INT_MAX-1;
        }
        for(int i = 2; i<=n; i++)
            for(int j = 1; j<= amount; j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
};

// class Solution {
// public:
//     int dp[13][10001];

//     int coinChange(vector<int>& coins, int amount) {
//         memset(dp, -1, sizeof(dp));
//         int ans = solve(coins, 0, amount);;
//         return ans == INT_MAX-1 ? -1 : ans;
//     }
//     int solve(vector<int>& coins, int i, int amount)
//     {
//         if(amount <= 0 || i == coins.size())
//             {
//                 if(amount == 0)
//                     return 0;
//                 return INT_MAX-1;
//             }
//         if(dp[i][amount] != -1)
//             return dp[i][amount];
//         int ans;
//         if(coins[i] > amount)
//         {
//             int donottake = 0 + solve(coins, i+1, amount-0);
//             dp[i][amount] = ans = donottake;
//         }
//         else
//         {
//             int take = 1 + solve(coins, i, amount - coins[i]);
//             int donottake = 0 + solve(coins, i+1, amount - 0);
//             dp[i][amount] = ans = min(take, donottake);
//         }
//         return dp[i][amount] = ans;
//     }
// };

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