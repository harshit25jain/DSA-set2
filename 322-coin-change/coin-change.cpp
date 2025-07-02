class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int j = 0, n = coins.size(); j < n; ++j) {
            int coin = coins[j];
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
/*
We use a 1D DP array dp where dp[i] stores the minimum number of coins needed to form amount i.
Initialize dp[0] = 0 since 0 coins are needed to make amount 0.
Set all other dp[i] values to a large number (amount + 1), effectively "infinity".
For each coin, iterate from that coin's value up to amount:
For each i, try using the current coin: dp[i] = min(dp[i], dp[i - coin] + 1)
This means: To form amount i, take the best between the existing value and using one more of the current coin.
After processing, if dp[amount] is still INF, it's not possible to make the amount; return -1. Otherwise, return dp[amount].
*/
