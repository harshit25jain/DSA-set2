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